#include "esp_err.h"
#include "temp_humidity.h"
#ifndef MQTT_PRODUCER_H
#define MQTT_PRODUCER_H

esp_err_t mqtt_start(void);
void mqtt_send_message(TempHumidity* temp_humidity);


#endif // MQTT_PRODUCER_H