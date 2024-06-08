#ifndef TEMP_HUMIDITY_H
#define TEMP_HUMIDITY_H
#include <freertos/FreeRTOS.h>

typedef struct
{
    float temperature;
    float humidity;
} TempHumidity;

#endif // TEMP_HUMIDITY_H