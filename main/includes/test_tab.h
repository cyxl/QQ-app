#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define TEST_TAB_NAME "TEST"

TaskHandle_t TestTab_Handle;

void test_tab_task(void *pvParameters);
void display_test_tab(lv_obj_t* tv);