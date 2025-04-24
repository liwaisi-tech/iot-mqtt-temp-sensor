idf_component_register(SRCS "iot-mqtt-temp-sensor.c"
                    INCLUDE_DIRS "."
                    REQUIRES "wifi" "temp_humidity_reader" "nvs_flash" "driver" "workflow")
list(APPEND EXTRA_COMPONENT_DIRS "components")