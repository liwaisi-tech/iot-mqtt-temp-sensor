#include <dht_task.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <queue_reader.h>
#include <temp_humidity.h>
#include <wifi.h>
#include <mqtt_producer.h>
#include <nvs_flash.h>

static const char *TAG = "liwaisi-esp32-app";

QueueHandle_t buffer;

void log_startup_info() {
    ESP_LOGI(TAG, "Startup..");
    ESP_LOGI(TAG, "Free memory: %" PRIu32 " bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "IDF version: %s", esp_get_idf_version());
}

void app_main(void)
{
    log_startup_info();
    // Initialize wifi
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    ESP_ERROR_CHECK(wifi_init_sta());
    ESP_ERROR_CHECK(mqtt_start());

    //create the queue buffer with a size of 10 4-byte elements
    buffer = xQueueCreate(10, sizeof(TempHumidity));
    // Create the tasks
    xTaskCreate(&task_read_temp_humidity, "task_read_temp_humidity", 4096, NULL, 5, NULL);
    xTaskCreate(&task_receive_queue_message, "task_receive_queue_message", 4096, NULL, 5, NULL);
}

