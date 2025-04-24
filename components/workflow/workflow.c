#include <stdio.h>
#include "workflow.h"
#include "esp_log.h"
#include <wifi.h>
#include <temp_humidity_reader.h>
#include "temp_humidity.h"
#include <mqtt_producer.h>

static const char *TAG = "workflow";

esp_err_t run_temp_humidity_workflow(void) {
    TempHumidity data;
    esp_err_t ret = read_temp_humidity(&data);
    if (ret != ESP_OK) {
        return ret;
    }
    ESP_LOGI(TAG, "Temperature: %f, Humidity: %f", data.temperature, data.humidity);
    ret = wifi_init_sta();
    if (ret != ESP_OK) {
        return ret;
    }
    ret = mqtt_start();
    if (ret != ESP_OK) {
        return ret;
    }
    mqtt_send_message(&data);
    return ESP_OK;
}