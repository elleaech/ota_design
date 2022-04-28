#ifndef __WIFI_STATION_H__
#define __WIFI_STATION_H__

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include <esp_err.h>

#include "lwip/err.h"
#include "lwip/sys.h"

/* The examples use WiFi configuration that you can set via project configuration menu

   If you'd rather not, just change the below entries to strings with
   the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/
#define EXAMPLE_ESP_WIFI_SSID      "ANALU OI FIBRA"
#define EXAMPLE_ESP_WIFI_PASS      "Analu272409"
#define EXAMPLE_ESP_MAXIMUM_RETRY  10

void wifi_init_sta(void);

#endif /* #ifndef __WIFI_STATION_H__ */
