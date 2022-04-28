#include "ota_log.h"
#include "ota.h"

#include "wifi_station.h"

#define EXAMPLE_ESP_OTA_URL        "http://192.168.1.6:80/Logbox_Wifi_OTA_V1.33.fw"


/* ---------------------------------------------------------------------- */
void app_main(void)
{
    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_sta();

    HTTP http_data = {
        .url = EXAMPLE_ESP_OTA_URL,
    };

    lb_ota_update_firmware_perform(&http_data, NULL, NULL);
}