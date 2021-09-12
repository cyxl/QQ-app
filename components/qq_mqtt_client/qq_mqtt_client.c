
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "esp_tls.h"
#include "cJSON.h"
#include <sys/param.h>

#include "core2forAWS.h"
#include "qq_mqtt_client.h"

#define SUBSCRIBE_TOPIC_LEN (CLIENT_ID_LEN + 3)
#define JSON_BUFSIZE 1024 * 2
#define CLIENT_ID_LEN (ATCA_SERIAL_NUM_SIZE * 2)

static const char *TAG = "QQ_MQTT_CLIENT";
static const char *CONFIG_BROKER_URI = "mqtts://ahdizksxaeeun-ats.iot.us-east-2.amazonaws.com:8883";

extern const uint8_t root_CA_crt_start[] asm("_binary_root_CA_crt_start");
extern const uint8_t root_CA_crt_end[] asm("_binary_root_CA_crt_end");
extern const uint32_t root_CA_crt_length;
extern const uint8_t qq_device_pem_start[] asm("_binary_qq_device_pem_start");
extern const uint8_t qq_device_pem_end[] asm("_binary_qq_device_pem_end");
extern const uint32_t qq_device_pem_length;

extern const uint8_t qq_private_pem_start[] asm("_binary_qq_private_pem_start");
extern const uint8_t qq_private_pem_end[] asm("_binary_qq_private_pem_end");
extern const uint32_t qq_private_pem_length;

extern const uint8_t qq_public_pem_start[] asm("_binary_qq_public_pem_start");
extern const uint8_t qq_public_pem_end[] asm("_binary_qq_public_pem_end");
extern const uint32_t qq_public_pem_length;

static esp_mqtt_client_handle_t glb_client;

static bool is_inited = false;
static const char *json_buf = NULL;
static char game_topic[64];
#define LEADER_MSG_TYPE 2
#define QUESTION_MSG_TYPE 3
#define QUESTION_RESPONSE_MSG_TYPE 1
char question[256];
int correct_answer_idx = -2;
char answers[4][128];
char current_leaders[LEADER_COUNT][32];
int current_leader_scores[LEADER_COUNT];
static const char *qq_client_id = CONFIG_QQ_CLIENT_ID;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    esp_mqtt_event_handle_t event = event_data;
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        msg_id = esp_mqtt_client_subscribe(client, game_topic, 0);
        ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);

        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        break;

    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGD(TAG, "MQTT_EVENT_DATA");
        //printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
        //printf("DATA=%.*s\r\n", event->data_len, event->data);

        event->data[event->data_len] = '\0';
        printf("data size %d", event->data_len);
        cJSON *message_json = cJSON_Parse(event->data);
        printf("e data %s\n", event->data);
        printf("json %s\n", cJSON_Print(message_json));
        if (message_json == NULL)
        {
            fprintf(stderr, "Error with json");
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL)
            {
                fprintf(stderr, "Error before: %s\n", error_ptr);
            }
        }
        else
        {
            cJSON *msgtype = cJSON_GetObjectItemCaseSensitive(message_json, "msgtype");
            printf("msgtype %d\n", msgtype->valueint);
            if (msgtype->valueint == 2)
            {
                cJSON *leaders = cJSON_GetObjectItemCaseSensitive(message_json, "leaders");
                for (int i = 0; i < cJSON_GetArraySize(leaders) && i < LEADER_COUNT; i++)
                {
                    cJSON *n = cJSON_GetArrayItem(leaders, i);
                    cJSON *player_id = cJSON_GetObjectItemCaseSensitive(n, "player_id");
                    cJSON *count = cJSON_GetObjectItemCaseSensitive(n, "count");
                    strncpy(current_leaders[i], player_id->valuestring, 32);
                    current_leader_scores[i] = count->valueint;
                }
            }
            else if (msgtype->valueint == 3)
            {
                //cJSON *cat = cJSON_GetObjectItemCaseSensitive(message_json, "category");
                //cJSON *type = cJSON_GetObjectItemCaseSensitive(message_json, "type");
                // cJSON *dif = cJSON_GetObjectItemCaseSensitive(message_json, "difficulty");
                cJSON *msg_q = cJSON_GetObjectItemCaseSensitive(message_json, "question");
                cJSON *c_ans_idx = cJSON_GetObjectItemCaseSensitive(message_json, "correct_answer_index");
                cJSON *ans = cJSON_GetObjectItemCaseSensitive(message_json, "answers");

                strcpy(question, msg_q->valuestring);
                correct_answer_idx = c_ans_idx->valueint;

                for (int i = 0; i < cJSON_GetArraySize(ans); i++)
                {
                    cJSON *n = cJSON_GetArrayItem(ans, i);
                    strcpy(answers[i], n->valuestring);
                }
                for (int i = cJSON_GetArraySize(ans); i < 4; i++)
                {
                    bzero(answers[i], 128);
                }
            }
            cJSON_Delete(message_json);
        }
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT)
        {
            ESP_LOGI(TAG, "Last error code reported from esp-tls: 0x%x", event->error_handle->esp_tls_last_esp_err);
            ESP_LOGI(TAG, "Last tls stack error number: 0x%x", event->error_handle->esp_tls_stack_err);
            ESP_LOGI(TAG, "Last captured errno : %d (%s)", event->error_handle->esp_transport_sock_errno,
                     strerror(event->error_handle->esp_transport_sock_errno));
        }
        else if (event->error_handle->error_type == MQTT_ERROR_TYPE_CONNECTION_REFUSED)
        {
            ESP_LOGI(TAG, "Connection refused error: 0x%x", event->error_handle->connect_return_code);
        }
        else
        {
            ESP_LOGW(TAG, "Unknown error type: 0x%x", event->error_handle->error_type);
        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

void send_answer(char *player_id, bool right_wrong, unsigned time)
{
    printf("sending answer\n");

    if (!is_inited)
    {
        ESP_LOGW(TAG, "MQTT NOT INITED!!!");
        return;
    }
    cJSON *ans = cJSON_CreateObject();
    cJSON *type = cJSON_CreateNumber(1);
    cJSON *correct = cJSON_CreateBool(right_wrong);
    cJSON *client_player_id = cJSON_CreateString(player_id);

    cJSON_AddItemToObject(ans, "msgtype", type);
    cJSON_AddItemToObject(ans, "player_id", client_player_id);
    cJSON_AddItemToObject(ans, "correct", correct);

    cJSON_PrintPreallocated(ans, json_buf, JSON_BUFSIZE, false);
    int pub_ret = esp_mqtt_client_publish(glb_client, game_topic, json_buf, 0, 1, 0);
    //ESP_LOGI(TAG, "Publishing of =%s returned=%d", out, pub_ret);

    cJSON_Delete(ans);
}

void qq_mqtt_client_init(int game_id)
{

    ESP_LOGI(TAG, "init");
    //TODO use defines
    bzero(question, 256);
    bzero(answers, 4 * 128);

    sprintf(game_topic, "qq/game/%d", 0);

    ESP_LOGI(TAG, "Client ID:%s", qq_client_id);
    json_buf = malloc(JSON_BUFSIZE);
    esp_err_t esp_ret = ESP_FAIL;

    esp_ret = esp_tls_set_global_ca_store(root_CA_crt_start, root_CA_crt_length + 1);
    if (esp_ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Error in setting the global ca store: [%02X] (%s),could not complete the https_request using global_ca_store", esp_ret, esp_err_to_name(esp_ret));
        return;
    }

    const esp_mqtt_client_config_t mqtt_cfg = {
        .uri = CONFIG_BROKER_URI,
        .client_cert_pem = (const char *)qq_device_pem_start,
        .client_key_pem = (const char *)qq_private_pem_start,
        .protocol_ver = MQTT_PROTOCOL_V_3_1_1,
        .use_global_ca_store = true,
        .client_id = qq_client_id};

    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    glb_client = esp_mqtt_client_init(&mqtt_cfg);
    /* The last argument may be used to pass data to the event handler, in this example mqtt_event_handler */
    esp_mqtt_client_register_event(glb_client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);

    ESP_LOGI(TAG, "[APP] Startup..");
    ESP_LOGI(TAG, "[APP] Free memory: %d bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_VERBOSE);
    esp_log_level_set("esp-tls", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_CLIENT", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_EXAMPLE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_BASE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("OUTBOX", ESP_LOG_VERBOSE);

    esp_mqtt_client_start(glb_client);
    is_inited = true;
}

void check_null(cJSON *p, int l)
{
    if (p == NULL)
        ESP_LOGI(TAG, "!!!!!!!!!!!!!!!!  cJSON NULL  !!!!!!!!!!!!!!!!!!! %d", l);
}

void fdump(float **buf, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ESP_LOGI("FLOATBUF", "i:%d,j:%d,v:%f\n", i, j, buf[i][j]);
        }
    }
}
