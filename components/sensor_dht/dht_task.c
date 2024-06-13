#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <temp_humidity.h>
#include <dht.h>
#include <esp_system.h>
#include <esp_mac.h>

#define SENSOR_TYPE DHT_TYPE_AM2301
#define GPIO_NUM GPIO_NUM_4

extern QueueHandle_t buffer;

char* get_mac_address_string(uint8_t mac[6]) {
    static char mac_str[18];
    sprintf(mac_str, "%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return mac_str;
}

void task_read_temp_humidity(void *pvParameter)
{
    while (true)
    {   
        TempHumidity data;
        ESP_ERROR_CHECK(dht_read_float_data(SENSOR_TYPE, GPIO_NUM_4, &data.humidity, &data.temperature));
        // call the function to get the mac address
        uint8_t mac[6];
        esp_read_mac(mac, ESP_MAC_WIFI_STA);
        data.mac_address = get_mac_address_string(mac);
        // Send the temperature and humidity to the buffer
        xQueueSend(buffer, &data, 0);
        fflush(stdout);
        for(int i = 30; i > 0; i--) {
            printf("\rWaiting for the next sensor data acquisition in %d seconds", i);
            fflush(stdout);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            if (i == 1) {
                printf("\n");
            }
        }
        
    }
}