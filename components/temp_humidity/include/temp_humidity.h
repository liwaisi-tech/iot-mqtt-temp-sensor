#ifndef TEMP_HUMIDITY_H
#define TEMP_HUMIDITY_H
#include <freertos/FreeRTOS.h>

typedef struct
{
    char* mac_address;
    float temperature;
    float humidity;
} TempHumidity;

char* convert_to_json_string(TempHumidity* data);

#endif // TEMP_HUMIDITY_H