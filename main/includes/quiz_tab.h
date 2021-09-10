#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define QUIZ_TAB_NAME "QUIZ"

TaskHandle_t QuizTab_Handle;

void quiz_tab_task(void *pvParameters);
void display_quiz_tab(lv_obj_t* tv);
void clear();