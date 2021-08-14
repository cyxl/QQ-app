#include "test_tab.h"

void display_test_tab(lv_obj_t *tv)
{
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);
    lv_obj_t *test_tab = lv_tabview_add_tab(tv, GAME_TAB_NAME); // Create a tab
    lv_obj_t *cont;

    cont = lv_cont_create(test_tab, NULL);
    lv_obj_set_auto_realign(cont, true);                   /*Auto realign when the size changes*/
    lv_obj_align_origo(cont, NULL, LV_ALIGN_CENTER, 0, 0); /*This parametrs will be sued when realigned*/
    lv_cont_set_fit(cont, LV_FIT_TIGHT);
    lv_cont_set_layout(cont, LV_LAYOUT_COLUMN_MID);

    lv_obj_t *label = lv_label_create(cont, NULL);
    lv_label_set_text_fmt(label, "MOTIVE - MAZE");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(label, LV_VER_RES, LV_HOR_RES - 10);

    lv_obj_t *table = lv_table_create(cont, NULL);
    lv_table_set_col_cnt(table, 2);
    lv_table_set_row_cnt(table, 3);
    lv_obj_align(table, NULL, LV_ALIGN_CENTER, 0, 0);

    lv_table_set_cell_value(table, 0, 0, "Maze");
    lv_table_set_cell_value(table, 1, 0, "Level");
    lv_table_set_cell_value(table, 2, 0, "Name");

    lv_table_set_cell_value_fmt(table, 0, 1, "CrazeMaze");
    lv_table_set_cell_value_fmt(table, 1, 1, "7");
    lv_table_set_cell_value_fmt(table, 2, 1, "Stantonious");

    xSemaphoreGive(xGuiSemaphore);
}

void test_tab_task(void *pvParameters)
{
    vTaskSuspend(NULL);

    for (;;)
    {
        vTaskDelay(pdMS_TO_TICKS(100));

    }
     vTaskDelete(NULL); // Should never get to here...

}
