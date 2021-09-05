
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_log.h"

#include "core2forAWS.h"

#include "quiz_tab.h"

#define QUIZ_PLOT_WIDTH 280 
#define QUIZ_PLOT_HEIGHT 200

LV_IMG_DECLARE(a_squat);
LV_IMG_DECLARE(b_up);

static lv_color_t *cbuf;
void rebuild_quiz_canvas(lv_obj_t* canvas)
{
    lv_draw_label_dsc_t label_desc;
    lv_draw_label_dsc_init(&label_desc);
    label_desc.font = &lv_font_montserrat_12;
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);

    //Example of text
    lv_canvas_draw_text(canvas,1,1,300,&label_desc,"HELLO WORLD this is a very long line with some very long text to see what it is going to look like with a long questions????",LV_LABEL_ALIGN_LEFT);
    xSemaphoreGive(xGuiSemaphore);
}

void display_quiz_tab(lv_obj_t *tv)
{
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_t *quiz_tab = lv_tabview_add_tab(tv, QUIZ_TAB_NAME); // Create a tab

    cbuf = (lv_color_t *)heap_caps_malloc(LV_CANVAS_BUF_SIZE_TRUE_COLOR(QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT), MALLOC_CAP_DEFAULT | MALLOC_CAP_SPIRAM);
    lv_obj_t *canvas = lv_canvas_create(quiz_tab, NULL);
    lv_canvas_set_buffer(canvas, cbuf, QUIZ_PLOT_WIDTH, QUIZ_PLOT_HEIGHT, LV_IMG_CF_TRUE_COLOR);

    lv_obj_align(canvas, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 5);
    lv_canvas_fill_bg(canvas, LV_COLOR_WHITE, LV_OPA_COVER);


    //Example of adding an image
    lv_obj_t * img_a_squat = lv_img_create(canvas, NULL);
    lv_img_set_src(img_a_squat, &a_squat);
    lv_obj_align(img_a_squat, NULL, LV_ALIGN_CENTER, 25, -20);

    lv_obj_t * img_b_up = lv_img_create(canvas, NULL);
    lv_img_set_src(img_b_up, &b_up);
    lv_obj_align(img_b_up, NULL, LV_ALIGN_CENTER, 50, -20);
    //End Example
    
    xSemaphoreGive(xGuiSemaphore);


    rebuild_quiz_canvas(canvas);
}

void quiz_tab_task(void *pvParameters)
{
    vTaskSuspend(NULL);

    for (;;)
    {
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete(NULL); // Should never get to here...
}
