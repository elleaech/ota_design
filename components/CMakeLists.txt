idf_component_register(SRCS "ota/ota.c" "ota/esp32/esp32.c"
                    INCLUDE_DIRS "ota/include"
                    REQUIRES esp_http_client esp_https_ota)
