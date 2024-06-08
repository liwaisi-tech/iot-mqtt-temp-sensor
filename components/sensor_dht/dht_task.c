#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <temp_humidity.h>
#include <dht.h>

#define SENSOR_TYPE DHT_TYPE_AM2301
#define GPIO_NUM GPIO_NUM_4

extern QueueHandle_t buffer;

void task_read_temp_humidity(void *pvParameter)
{
    while (true)
    {   
        TempHumidity data;

        ESP_ERROR_CHECK(dht_read_float_data(SENSOR_TYPE, GPIO_NUM_4, &data.humidity, &data.temperature));

        // Send the temperature and humidity to the buffer
        xQueueSend(buffer, &data, 0);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}