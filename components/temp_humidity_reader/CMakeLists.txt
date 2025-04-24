idf_component_register(SRCS "temp_humidity_reader.c"
                    INCLUDE_DIRS "include"
                    PRIV_REQUIRES "dht" "esp_system" "dtos")
