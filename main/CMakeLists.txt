set (COMPONENTS_DIR "../components/")

idf_component_register(SRCS "main.c" ${COMPONENTS_DIR}/station/wifi_station.c
                        INCLUDE_DIRS ${COMPONENTS_DIR}/station)
