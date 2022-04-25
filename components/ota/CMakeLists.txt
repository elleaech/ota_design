idf_component_register(SRCS "ota.c" "esp32/esp32.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_http_client esp_https_ota)
