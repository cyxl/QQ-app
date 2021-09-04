set(SOURCES main.c)
idf_component_register(SRCS quiz_tab.c app_wifi.c button_handler.c game_tab.c test_tab.c main.c
                       INCLUDE_DIRS . includes
                       REQUIRES mot_mqtt_client core2forAWS esp-tls esp_http_client esp-cryptoauthlib nvs_flash )

