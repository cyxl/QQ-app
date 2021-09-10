
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_log.h"

#include "core2forAWS.h"

#include "button_handler.h"
#include "quiz_tab.h"

static const char *TAG = "BUTTON_HANDLER";

void init_button_handlers(void)
{

    xTaskCreatePinnedToCore(button_handler_task, "ButtonTask", 2048, NULL, 1, &button_handle, 1);
}

void button_handler_task(void *pvParameters)
{

    ESP_LOGI(TAG, "Handling buttons");
    for (;;)
    {
        if (Button_WasPressed(button_right))
        {
            xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
            static const char *btns[] = {"Close", ""};

            lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
            lv_msgbox_set_text(mbox1, "Cleared");
            lv_msgbox_add_btns(mbox1, btns);
            lv_obj_set_width(mbox1, 200);
            lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); /*Align to the corner*/
            xSemaphoreGive(xGuiSemaphore);
            clear();
        }
        if (Button_WasPressed(button_left))
        {
            //open
        }
        if (Button_WasPressed(button_middle))
        {
            //open
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
