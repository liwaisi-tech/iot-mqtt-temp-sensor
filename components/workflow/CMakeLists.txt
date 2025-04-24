idf_component_register(SRCS "workflow.c"
                    INCLUDE_DIRS "include"
                    PRIV_REQUIRES "dht" "esp_system" "dtos" "mqtt_producer" "wifi" "temp_humidity_reader")
