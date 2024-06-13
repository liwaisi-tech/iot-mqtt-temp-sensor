#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>
#include <temp_humidity.h>


// Function to convert TempHumidity struct to JSON string
char* convert_to_json_string(TempHumidity* data) {
    // Create a cJSON object
    cJSON *json = cJSON_CreateObject();

    // Add data to the JSON object
    if (data->mac_address) {
        cJSON_AddStringToObject(json, "mac_address", data->mac_address);
    }
    cJSON_AddNumberToObject(json, "temperature", data->temperature);
    cJSON_AddNumberToObject(json, "humidity", data->humidity);

    // Convert cJSON object to string
    char *json_string = cJSON_Print(json);

    // Clean up cJSON object
    cJSON_Delete(json);

    return json_string; // Remember to free this string after use
}