idf_component_register(SRCS "ota_lib/esp32/esp32.c"
                            "ota_lib/esp32/esp32_log.c"
                    INCLUDE_DIRS "ota_lib/include"
                    REQUIRES esp_http_client esp_https_ota)
