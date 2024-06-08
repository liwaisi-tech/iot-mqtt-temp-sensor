#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <dht_task.h>
#include <queue_reader.h>
#include <temp_humidity.h>

QueueHandle_t buffer;

void app_main(void)
{
    //create the queue buffer with a size of 10 4-byte elements
    buffer = xQueueCreate(10, sizeof(TempHumidity));

    // Create the tasks
    xTaskCreate(&task_read_temp_humidity, "task_read_temp_humidity", 4096, NULL, 5, NULL);
    xTaskCreate(&task_receive_queue_message, "task_receive_queue_message", 4096, NULL, 5, NULL);
}
