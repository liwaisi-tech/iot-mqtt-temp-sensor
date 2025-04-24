#include <stdio.h>
#include "temp_humidity_reader.h"
#include "dht.h"
#include "esp_err.h"

#define SENSOR_TYPE DHT_TYPE_AM2301
#define GPIO_NUM GPIO_NUM_4

esp_err_t read_temp_humidity(TempHumidity* data)
{
    esp_err_t ret = dht_read_float_data(SENSOR_TYPE, GPIO_NUM, &data->humidity, &data->temperature);
    if (ret != ESP_OK) {
        return ret;
    }
    return ESP_OK;
}
