
#ifndef _QQ_CLIENT2_H
#define _QQ_CLIENT2_H

#include "freertos/task.h"

TaskHandle_t MotMqttClientHandle;

void qq_mqtt_client_init(int game_id);

extern char question[256];
extern int correct_answer_idx;
extern char answers[4][128];
#endif