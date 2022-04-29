#include "ota_log.h"
#include "ota.h"

#include "wifi_station.h"
#include <inttypes.h>
#include <esp_log.h>

#define EXAMPLE_ESP_OTA_URL        "http://192.168.1.6:80/factory_WROOM-32.bin"


/* ---------------------------------------------------------------------- */
void app_main(void)
{
    esp_err_t ret = ESP_FAIL;
    int32_t rc = OTA_ERROR;

    HTTP http_data = {
        .url = EXAMPLE_ESP_OTA_URL,
    };

    //Initialize NVS
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_sta();

    rc = lb_ota_update_firmware_perform(&http_data, NULL, NULL);
    lb_ota_update_firmware_finish(rc);
}