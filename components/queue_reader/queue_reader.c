#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <temp_humidity.h>
#include <mqtt_producer.h>

extern QueueHandle_t buffer;

void task_receive_queue_message(void *pvParameter)
{
    while (true)
    {
        TempHumidity data;

        // Receive the temperature and humidity from the buffer
        xQueueReceive(buffer, &data, portMAX_DELAY);

        // Print the temperature and humidity
        fflush(stdout);
        printf("Temperature: %.1f C, Humidity: %.1f %%\n", data.temperature, data.humidity);

        // Send the temperature and humidity to the MQTT broker
        mqtt_send_message(data);
    }
}
