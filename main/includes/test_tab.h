#pragma once

#define MAZE_TAB_NAME "MAZE"

TaskHandle_t TestTab_Handle;

void test_tab_task(void *pvParameters);
void display_test_tab(lv_obj_t* tv);