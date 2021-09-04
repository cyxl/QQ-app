#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"

#include "esp_freertos_hooks.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_vfs_fat.h"
#include "driver/gpio.h"
#include "driver/spi_common.h"
#include "sdmmc_cmd.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"

#include "core2forAWS.h"
#include "game_tab.h"
#include "test_tab.h"
#include "quiz_tab.h"
#include "button_handler.h"
#include "app_wifi.h"

static const char *TAG = "MAIN";

static void ui_start(void);
static lv_obj_t *tab_view;

static void tab_event_cb(lv_obj_t *slider, lv_event_t event);

void app_main(void)
{
    ESP_LOGI(TAG, "\n***************************************************\n Quiz Quest \n***************************************************");

    // Initialize NVS for Wi-Fi stack to store data
    //TODO esp_err_t ret = nvs_flash_init();
    //if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    //{
    //    ESP_ERROR_CHECK(nvs_flash_erase());
     //   ret = nvs_flash_init();
   // }
    //ESP_ERROR_CHECK(ret);

    esp_log_level_set("gpio", ESP_LOG_NONE);
    esp_log_level_set("ILI9341", ESP_LOG_NONE);

    Core2ForAWS_Init();
    Core2ForAWS_Display_SetBrightness(40); // Last since the display first needs time to finish initializing.
    //init_tf();

    ui_start();

/* TODO 
    int wifi_retries = 3;
    int connected = init_wifi();
    while (!connected && wifi_retries >= 0)
    {
        wifi_retries -= 1;

        ESP_LOGI(TAG, "=====Unable to connect to WiFi...retrying=====");

        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
        static const char *btns[] = {"Close", ""};
        lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
        lv_msgbox_set_text(mbox1, "Wifi Failed");
        lv_msgbox_add_btns(mbox1, btns);
        lv_obj_set_width(mbox1, 200);
        lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); 
        xSemaphoreGive(xGuiSemaphore);
        connected = init_wifi();
    }

    if (connected){
        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
        static const char *btns[] = {"Close", ""};
        lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
        lv_msgbox_set_text(mbox1, "Wifi Connected");
        lv_msgbox_add_btns(mbox1, btns);
        lv_obj_set_width(mbox1, 200);
        lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0); 
        xSemaphoreGive(xGuiSemaphore);

    }
*/
    //TODO maze_client_init();
    //TODO mot_mqtt_client_init();
}

static void ui_start(void)
{
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_t *top_scr = lv_obj_create(NULL, NULL);

    lv_scr_load_anim(top_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 400, 0, false);
    //Tab setup
    tab_view = lv_tabview_create(top_scr, NULL);
    lv_obj_set_event_cb(tab_view, tab_event_cb);
    lv_tabview_set_btns_pos(tab_view, LV_TABVIEW_TAB_POS_NONE);

    xSemaphoreGive(xGuiSemaphore);

    display_game_tab(tab_view);
    //display_test_tab(tab_view);
    display_quiz_tab(tab_view);
    init_button_handlers();
}

static void tab_event_cb(lv_obj_t *slider, lv_event_t event)
{
    if (event == LV_EVENT_VALUE_CHANGED)
    {
        lv_tabview_ext_t *ext = (lv_tabview_ext_t *)lv_obj_get_ext_attr(tab_view);
        const char *tab_name = ext->tab_name_ptr[lv_tabview_get_tab_act(tab_view)];
        ESP_LOGI(TAG, "Current Active Tab: %s\n", tab_name);

        //vTaskSuspend(TestTab_Handle);

        if (strcmp(tab_name, TEST_TAB_NAME) == 0)
        {
            vTaskResume(TestTab_Handle);
        }
    }
}
