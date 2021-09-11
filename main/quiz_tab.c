
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_log.h"

#include "core2forAWS.h"
#include "qq_mqtt_client.h"
#include "quiz_tab.h"

#include "mot-imu-tf.h"

#define QUIZ_PLOT_WIDTH 280
#define QUIZ_PLOT_HEIGHT 185

#define NUM_ACTIONS 6
#define INF_WAIT_MS 600 

#define NUM_ACTION_CLASSES 9
#define B_UP 1
#define B_DOWN 2
#define B_JUMP 5
#define B_SQUAT 6
#define B_LEFT 7
#define B_RIGHT 8

#define A_UP B_UP + NUM_ACTION_CLASSES
#define A_DOWN B_DOWN + NUM_ACTION_CLASSES
#define A_JUMP B_JUMP + NUM_ACTION_CLASSES
#define A_LEFT B_LEFT + NUM_ACTION_CLASSES
#define A_RIGHT B_RIGHT + NUM_ACTION_CLASSES
#define A_SQUAT B_SQUAT + NUM_ACTION_CLASSES

#define ICON_WIDTH 20
#define ICON_PAD 2

LV_IMG_DECLARE(a_squat);
LV_IMG_DECLARE(b_squat);
LV_IMG_DECLARE(a_up);
LV_IMG_DECLARE(b_up);
LV_IMG_DECLARE(a_down);
LV_IMG_DECLARE(b_down);
LV_IMG_DECLARE(a_left);
LV_IMG_DECLARE(b_left);
LV_IMG_DECLARE(a_right);
LV_IMG_DECLARE(b_right);
LV_IMG_DECLARE(a_jump);
LV_IMG_DECLARE(b_jump);

static lv_color_t *cbuf;
static lv_draw_label_dsc_t label_desc;
static lv_draw_line_dsc_t line_desc;
char current_question[256];

static bool q_action_states[4][NUM_ACTIONS] = {false}; //Update will data from model inference
static int state_check_idx[4] = {0};

void draw_answer_line(lv_obj_t *canvas, int x_pos, int y_pos, char *ans, int actions[NUM_ACTIONS], bool on_off[NUM_ACTIONS], int num_actions)
{
    lv_canvas_draw_text(canvas, x_pos, y_pos, 300, &label_desc, ans, LV_LABEL_ALIGN_LEFT);
    static lv_point_t t[2];

    t[0].x = x_pos;
    t[0].y = y_pos;
    t[1].x = x_pos + QUIZ_PLOT_WIDTH - x_pos * 2;
    t[1].y = y_pos;
    lv_canvas_draw_line(canvas, t, 2, &line_desc);

    for (int i = 0; i < num_actions; i++)
    {
        lv_obj_t *n_img = lv_img_create(canvas, NULL);
        int act = actions[i];
        if (on_off[i] == true)
        {
            act = act + NUM_ACTION_CLASSES; //turn to a_
        }
        switch (act)
        {
        case B_UP:
            lv_img_set_src(n_img, &b_up);
            break;
        case B_DOWN:
            lv_img_set_src(n_img, &b_down);
            break;
        case B_JUMP:
            lv_img_set_src(n_img, &b_jump);
            break;
        case B_LEFT:
            lv_img_set_src(n_img, &b_left);
            break;
        case B_RIGHT:
            lv_img_set_src(n_img, &b_right);
            break;
        case B_SQUAT:
            lv_img_set_src(n_img, &b_squat);
            break;
        case A_UP:
            lv_img_set_src(n_img, &a_up);
            break;
        case A_DOWN:
            lv_img_set_src(n_img, &a_down);
            break;
        case A_JUMP:
            lv_img_set_src(n_img, &a_jump);
            break;
        case A_LEFT:
            lv_img_set_src(n_img, &a_left);
            break;
        case A_RIGHT:
            lv_img_set_src(n_img, &a_right);
            break;
        case A_SQUAT:
            lv_img_set_src(n_img, &a_squat);
            break;
        default:
            printf("UNKNOWN ACTION!!!! %d", act);
        }
        lv_obj_align(n_img, NULL, LV_ALIGN_IN_TOP_LEFT, (ICON_WIDTH * i) + (ICON_PAD * i), y_pos + 15);
    }
    t[0].x = x_pos;
    t[0].y = y_pos + 35;
    t[1].x = x_pos + QUIZ_PLOT_WIDTH - x_pos * 2;
    t[1].y = y_pos + 35;

    lv_canvas_draw_line(canvas, t, 2, &line_desc);
}

void rebuild_quiz_canvas(lv_obj_t *canvas,
                         char *question,
                         char *ans1,
                         char *ans2,
                         char *ans3,
                         char *ans4,
                         int actions[4][NUM_ACTIONS], bool on_off[4][NUM_ACTIONS], int num_actions)
{
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_clean(canvas);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);
    lv_canvas_draw_text(canvas, 1, 1, QUIZ_PLOT_WIDTH, &label_desc, question, LV_LABEL_ALIGN_LEFT);
    draw_answer_line(canvas, 2, 45, ans1, actions[0], on_off[0], num_actions);
    draw_answer_line(canvas, 2, 80, ans2, actions[1], on_off[1], num_actions);
    draw_answer_line(canvas, 2, 115, ans3, actions[2], on_off[2], num_actions);
    draw_answer_line(canvas, 2, 150, ans4, actions[3], on_off[3], num_actions);

    xSemaphoreGive(xGuiSemaphore);
}

void display_quiz_tab(lv_obj_t *tv)
{
    bzero(current_question, 256);
    lv_draw_line_dsc_init(&line_desc);
    lv_draw_label_dsc_init(&label_desc);
    label_desc.font = &lv_font_montserrat_12;

    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_t *quiz_tab = lv_tabview_add_tab(tv, QUIZ_TAB_NAME); // Create a tab

    //Leader board
    lv_obj_t *leader_lbl = lv_label_create(quiz_tab, NULL);
    lv_label_set_long_mode(leader_lbl, LV_LABEL_LONG_SROLL_CIRC); /*Circular scroll*/
    lv_obj_set_width(leader_lbl, 290);
    lv_label_set_recolor(leader_lbl,true);
    lv_label_set_text(leader_lbl, "#0000ff Leader Board: Brayden:190 Dad:12 FooBar:1#");
    lv_obj_align(leader_lbl, NULL, LV_ALIGN_IN_TOP_MID, 0, 2);

    //Main canvas
    cbuf = (lv_color_t *)heap_caps_malloc(LV_CANVAS_BUF_SIZE_TRUE_COLOR(QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT), MALLOC_CAP_DEFAULT | MALLOC_CAP_SPIRAM);
    lv_obj_t *canvas = lv_canvas_create(quiz_tab, NULL);
    lv_canvas_set_buffer(canvas, cbuf, QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, NULL, LV_ALIGN_IN_TOP_LEFT, 2, 22);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);
    xSemaphoreGive(xGuiSemaphore);

    static lv_obj_t *quiz_parms[2];
    quiz_parms[0] = canvas;
    quiz_parms[1] = leader_lbl;

    xTaskCreatePinnedToCore(quiz_tab_task, "QuizTask", 2048 * 2, quiz_parms, 1, &QuizTab_Handle, 0);
}

void clear()
{
    //TODO wrap in semaphore
    bzero(q_action_states, 4 * NUM_ACTIONS * sizeof(bool));
    bzero(state_check_idx, 4 * sizeof(int));
}

int get_answer(bool states[4][NUM_ACTIONS])
{
    for (int i = 0; i < 4; i++)
    {
        bool alltrue = true;
        for (int j = 0; j < NUM_ACTIONS; j++)
        {
            alltrue &= states[i][j];
        }
        if (alltrue == true)
            return i;
    }
    return -1;
}

void shuffle_actions(int all_actions[6], int actions[4][NUM_ACTIONS])
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < NUM_ACTIONS; j++)
        {
            int r_act = all_actions[rand() % NUM_ACTIONS];
            actions[i][j] = r_act;
        }
    }
}

void quiz_tab_task(void *pvParameters)
{
    srand(time(NULL));
    vTaskSuspend(NULL);
    lv_obj_t **quiz_parms = (lv_obj_t **)pvParameters;
    lv_obj_t *canvas = (lv_obj_t *)quiz_parms[0];

    int q_actions[4][NUM_ACTIONS] = {0}; //Randomly generate using rand()
    static int actions[6] = {B_UP, B_DOWN, B_LEFT, B_RIGHT, B_SQUAT, B_JUMP};

    for (;;)
    {

        int inf = get_latest_inf(4);
        printf("inf : %d\n", inf);

        if (strcmp(current_question, question) != 0)
        {
            strcpy(current_question, question);
            clear();
            shuffle_actions(actions, q_actions);
        }

        for (int i = 0; i < 4; i++)
        {
            if (q_actions[i][state_check_idx[i]] == inf)
            {
                //TODO wrap in sema
                q_action_states[i][state_check_idx[i]] = true;
                state_check_idx[i] = state_check_idx[i] + 1;
            }
        }

        int answer = get_answer(q_action_states);

        if (answer >= 0)
        {

            xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
            static const char *btns[] = {"Close", ""};

            lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
            lv_msgbox_set_text_fmt(mbox1, "Ans: %d", answer);
            lv_msgbox_add_btns(mbox1, btns);
            lv_obj_set_width(mbox1, 200);
            lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/
            xSemaphoreGive(xGuiSemaphore);
            clear();
        }

        rebuild_quiz_canvas(canvas,
                            question,
                            correct_answer,
                            incorrect_answers[0],
                            incorrect_answers[1],
                            incorrect_answers[2],
                            q_actions,
                            q_action_states,
                            NUM_ACTIONS);
        vTaskDelay(pdMS_TO_TICKS(300));
    }
    vTaskDelete(NULL); // Should never get to here...
}
