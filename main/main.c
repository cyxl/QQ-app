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
#include "qq_mqtt_client.h"
#include "button_handler.h"
#include "app_wifi.h"
#include "imu_task.h"
#include "mot-imu-tf.h"

static const char *TAG = "MAIN";

static void ui_start(void);
static lv_obj_t *tab_view;

static void tab_event_cb(lv_obj_t *slider, lv_event_t event);

void heap_caps_alloc_failed_hook(size_t requested_size, uint32_t caps, const char *function_name)
{
    printf("%s was called but failed to allocate %d bytes with 0x%X capabilities. \n", function_name, requested_size, caps);
    int stackSize = uxTaskGetStackHighWaterMark(NULL);
    int minHeap = xPortGetMinimumEverFreeHeapSize();
    int heapSize = xPortGetFreeHeapSize();
    int capsSize = heap_caps_get_free_size(caps);
    ESP_LOGI(TAG, "MAIN STACK HWM %d", stackSize);
    ESP_LOGI(TAG, "MAIN HEAP HWM %d", heapSize);
    ESP_LOGI(TAG, "MAIN MIN HEAP HWM %d", minHeap);
    ESP_LOGI(TAG, "MAIN CAPS HEAP HWM %d", capsSize);
}

void app_main(void)
{
    ESP_LOGI(TAG, "\n***************************************************\n Quiz Quest \n***************************************************");
    heap_caps_register_failed_alloc_callback(heap_caps_alloc_failed_hook);

    // Initialize NVS for Wi-Fi stack to store data
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
       ret = nvs_flash_init();
     }
    ESP_ERROR_CHECK(ret);

    esp_log_level_set("gpio", ESP_LOG_NONE);
    esp_log_level_set("ILI9341", ESP_LOG_NONE);

    Core2ForAWS_Init();
    Core2ForAWS_Display_SetBrightness(40); // Last since the display first needs time to finish initializing.
    //init_tf();

    init_imu();
    init_mot_imu();
    ui_start();
    int connected = init_wifi();

    //Core2ForAWS_Sk6812_SetSideColor(SK6812_SIDE_LEFT, (current_red << 16) + (current_green << 8) + (current_blue));
    static const char *btns[] = {"Close", ""};
    if (connected == true)
    {
        qq_mqtt_client_init(0);

        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
        lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
        lv_msgbox_set_text(mbox1, "Wifi Connected");
        lv_msgbox_add_btns(mbox1, btns);
        lv_obj_set_width(mbox1, 200);
        lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0);
        xSemaphoreGive(xGuiSemaphore);
    }
    else
    {
        xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
        lv_obj_t *mbox1 = lv_msgbox_create(lv_scr_act(), NULL);
        lv_msgbox_set_text(mbox1, "Wifi Failed");
        lv_msgbox_add_btns(mbox1, btns);
        lv_obj_set_width(mbox1, 200);
        lv_obj_align(mbox1, NULL, LV_ALIGN_CENTER, 0, 0);
        xSemaphoreGive(xGuiSemaphore);
    }


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

        vTaskSuspend(QuizTab_Handle);

        if (strcmp(tab_name, QUIZ_TAB_NAME) == 0)
        {
            vTaskResume(QuizTab_Handle);
        }
    }
}
