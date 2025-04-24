idf_component_register(SRCS "temp_humidity_reader.c"
                    INCLUDE_DIRS "include"
                    REQUIRES "dht" "esp_system" "dtos")
