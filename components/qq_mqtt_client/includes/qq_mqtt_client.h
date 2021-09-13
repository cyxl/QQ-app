
#ifndef _QQ_CLIENT2_H
#define _QQ_CLIENT2_H

#include "freertos/task.h"

TaskHandle_t MotMqttClientHandle;

void qq_mqtt_client_init(int game_id);
void send_answer(const char *player_id, bool right_wrong, unsigned time);

#define LEADER_COUNT 5

extern char question[256];
extern int correct_answer_idx;
extern char answers[4][128];
extern char current_leaders[LEADER_COUNT][32];
extern int current_leader_scores[LEADER_COUNT];
extern SemaphoreHandle_t qqMqttSemaphore;
#endif