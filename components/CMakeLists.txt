set (LIB "ota_lib")
set (PLATFORM "esp32_http")

idf_component_register(SRCS ${LIB}/${PLATFORM}/ota.c
                            ${LIB}/${PLATFORM}/ota_log.c
                    INCLUDE_DIRS ${LIB}/include
                                 ${LIB}/${PLATFORM}/
                    REQUIRES esp_http_client esp_https_ota app_update)
