
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

#define QUIZ_PLOT_WIDTH 290
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
static lv_color_t ans_colors[4] = {LV_COLOR_BLACK};
static const char *qq_client_id = CONFIG_QQ_CLIENT_ID;

static int steps = 0;

void draw_answer_line(lv_obj_t *canvas, int x_pos, int y_pos, char *ans, int actions[NUM_ACTIONS], bool on_off[NUM_ACTIONS], int num_actions, lv_color_t text_color)
{
    label_desc.color = text_color;
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
            // default:
            // printf("UNKNOWN ACTION!!!! %d", act);
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
                         char ans[4][128],
                         lv_color_t ans_colors[4],
                         int actions[4][NUM_ACTIONS],
                         bool on_off[4][NUM_ACTIONS],
                         int num_actions)
{
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_clean(canvas);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);
    lv_canvas_draw_text(canvas, 1, 1, QUIZ_PLOT_WIDTH, &label_desc, question, LV_LABEL_ALIGN_LEFT);
    draw_answer_line(canvas, 2, 45, ans[0], actions[0], on_off[0], num_actions, ans_colors[0]);
    draw_answer_line(canvas, 2, 80, ans[1], actions[1], on_off[1], num_actions, ans_colors[1]);
    draw_answer_line(canvas, 2, 115, ans[2], actions[2], on_off[2], num_actions, ans_colors[2]);
    draw_answer_line(canvas, 2, 150, ans[3], actions[3], on_off[3], num_actions, ans_colors[3]);

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
    lv_label_set_recolor(leader_lbl, true);
    lv_obj_align(leader_lbl, NULL, LV_ALIGN_IN_TOP_MID, 0, 2);

    // Bottom text
    lv_obj_t *bottom_lbl = lv_label_create(quiz_tab, NULL);
    lv_label_set_long_mode(bottom_lbl, LV_LABEL_LONG_SROLL_CIRC); /*Circular scroll*/
    lv_obj_set_width(bottom_lbl, 290);
    lv_label_set_recolor(bottom_lbl, true);
    lv_obj_align(bottom_lbl, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -15);

    //Main canvas
    cbuf = (lv_color_t *)heap_caps_malloc(LV_CANVAS_BUF_SIZE_TRUE_COLOR(QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT), MALLOC_CAP_DEFAULT | MALLOC_CAP_SPIRAM);
    lv_obj_t *canvas = lv_canvas_create(quiz_tab, NULL);
    lv_canvas_set_buffer(canvas, cbuf, QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, NULL, LV_ALIGN_IN_TOP_MID, 2, 22);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);
    xSemaphoreGive(xGuiSemaphore);

    static lv_obj_t *quiz_parms[3];
    quiz_parms[0] = canvas;
    quiz_parms[1] = leader_lbl;
    quiz_parms[2] = bottom_lbl;

    xTaskCreatePinnedToCore(quiz_tab_task, "QuizTask", 2048 * 2, quiz_parms, 1, &QuizTab_Handle, 0);
}

void clear()
{
    steps = 0;
    //TODO wrap in semaphore
    bzero(q_action_states, 4 * NUM_ACTIONS * sizeof(bool));
    bzero(state_check_idx, 4 * sizeof(int));
    ans_colors[0] = LV_COLOR_BLACK;
    ans_colors[1] = LV_COLOR_BLACK;
    ans_colors[2] = LV_COLOR_BLACK;
    ans_colors[3] = LV_COLOR_BLACK;
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

char *get_action_string(int inf)
{
    switch (inf)
    {
    case REST_LABEL:
        return "rest";
    case FORWARD_LABEL:
        return "forward";
    case BACKWARD_LABEL:
        return "backward";
    case LEFT_LABEL:
        return "left turn";
    case RIGHT_LABEL:
        return "right turn";
    case UP_LABEL:
        return "jump";
    case DOWN_LABEL:
        return "squat";
    case LEFTSIDE_LABEL:
        return "left slide";
    case RIGHTSIDE_LABEL:
        return "right slide";
    default:
        return "????";
    };
}
void quiz_tab_task(void *pvParameters)
{
    srand(time(NULL));
    vTaskSuspend(NULL);
    lv_obj_t **quiz_parms = (lv_obj_t **)pvParameters;
    lv_obj_t *canvas = (lv_obj_t *)quiz_parms[0];
    lv_obj_t *leader_lbl = (lv_obj_t *)quiz_parms[1];
    lv_obj_t *bottom_lbl = (lv_obj_t *)quiz_parms[2];

    long start_t = xTaskGetTickCount();
    bool inferring = true;

    int q_actions[4][NUM_ACTIONS] = {0}; //Randomly generate using rand()
    static int actions[6] = {B_UP, B_DOWN, B_LEFT, B_RIGHT, B_SQUAT, B_JUMP};

    for (;;)
    {
        int answer = get_answer(q_action_states);
        int inf = -1;
        if (inferring == true)
        {
            //inf = get_latest_inf(2,.6);
            inf = get_max_from_confs(4, .8);
        }
        printf("inf : %d\n", inf);

        if (inf >0 && inf != UNCERTAIN_LABEL) steps += 1;

        if (strcmp(current_question, question) != 0)
        {
            inferring = true;
            strcpy(current_question, question);
            clear();
            if (answer == -1)
                send_answer(qq_client_id, false, time(NULL));
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

        if (answer == correct_answer_idx)
        {

            xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
            static const char *btns[] = {"Close", ""};

            lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
            lv_msgbox_set_text_fmt(mbox1, "Correct");
            lv_msgbox_add_btns(mbox1, btns);
            lv_obj_set_width(mbox1, 200);
            lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/
            xSemaphoreGive(xGuiSemaphore);
            clear();
            send_answer(qq_client_id, true, time(NULL));
            inferring = false;
            ans_colors[answer] = LV_COLOR_GREEN;
            rebuild_quiz_canvas(canvas,
                                question,
                                answers,
                                ans_colors,
                                q_actions,
                                q_action_states,
                                NUM_ACTIONS);
        }
        else if (answer >= 0)
        {
            xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
            static const char *btns[] = {"Close", ""};

            lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
            lv_msgbox_set_text_fmt(mbox1, "Incorrect");
            lv_msgbox_add_btns(mbox1, btns);
            lv_obj_set_width(mbox1, 200);
            lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/
            xSemaphoreGive(xGuiSemaphore);
            clear();
            send_answer(qq_client_id, false, time(NULL));
            inferring = false;
            ans_colors[answer] = LV_COLOR_RED;
            rebuild_quiz_canvas(canvas,
                                question,
                                answers,
                                ans_colors,
                                q_actions,
                                q_action_states,
                                NUM_ACTIONS);
        }

        rebuild_quiz_canvas(canvas,
                            question,
                            answers,
                            ans_colors,
                            q_actions,
                            q_action_states,
                            NUM_ACTIONS);
        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
        lv_label_set_text_fmt(bottom_lbl, "#0000ff Action: %s Steps: %d Time: %d secs#", get_action_string(inf), steps, (int)((xTaskGetTickCount() - start_t)/100));
        lv_label_set_text_fmt(leader_lbl, "#0000ff Leader Board: %s:%d %s:%d %s:%d %s:%d %s:%d#",
                              current_leaders[0], current_leader_scores[0],
                              current_leaders[1], current_leader_scores[1],
                              current_leaders[2], current_leader_scores[2],
                              current_leaders[3], current_leader_scores[3],
                              current_leaders[4], current_leader_scores[4]);
        xSemaphoreGive(xGuiSemaphore);
        vTaskDelay(pdMS_TO_TICKS(400));
    }
    vTaskDelete(NULL); // Should never get to here...
}
