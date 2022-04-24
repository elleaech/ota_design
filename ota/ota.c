#include "ota.h"

#include <esp_err.h>
#include <esp_log.h>
#include <esp_system.h>
#include <esp_http_client.h>
#include <esp_https_ota.h>

/*
esp_http_client_config_t config = {
    .url = CONFIG_FIRMWARE_UPGRADE_URL,
    .cert_pem = (char *)"server_cert_pem_start",
};

esp_err_t ret = esp_https_ota(&config);

ESP_LOGI(__FUNCTION__, "ret=[%d]", ret);

if (ret == ESP_OK)
{
    esp_restart();
}
else
{
    return ESP_FAIL;
}
return ESP_OK;
*/

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_begin(void)
{
    //
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_perform(void)
{
    //
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_is_complete_data_received(void)
{
    //
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_get_img_desc(void)
{
    //
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_finish(void)
{
    //
}
