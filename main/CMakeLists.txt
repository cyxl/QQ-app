set(SOURCES main.c)
idf_component_register(SRCS quiz_tab.c app_wifi.c button_handler.c game_tab.c test_tab.c main.c
                       INCLUDE_DIRS . includes
                       EMBED_TXTFILES  ../certs/root_CA.crt ../certs/qq_private.pem ../certs/qq_public.pem ../certs/qq_device.pem
                       REQUIRES images qq_mqtt_client core2forAWS esp-tls esp_http_client esp-cryptoauthlib nvs_flash )

