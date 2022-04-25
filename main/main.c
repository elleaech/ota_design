#include "ota_data.h"
#include "ota_log.h"
#include "ota.h"

#include <stdio.h>
#include <stdlib.h>

static int32_t lb_set_params_(NovusOTA *ota_data);

/* ---------------------------------------------------------------------- */
void app_main(void)
{
    lb_ota_log_info(__FUNCTION__, "<%s>\n", __FUNCTION__);
    int rc = OTA_OK;

    NovusOTA *ota_data = NULL;

    rc = lb_ota_init_params(&ota_data);

    if (OTA_OK == rc && NULL != ota_data)
    {
        lb_ota_log_info(__FUNCTION__, "INIT SUCCESSFULL\n");
        rc = lb_set_params_(ota_data);

        if (OTA_OK == rc)
        {
            lb_ota_log_info(__FUNCTION__, "<%s>\n", "lb_ota_update_firmware");
            lb_ota_update_firmware(ota_data);
            lb_ota_log_info(__FUNCTION__, "</%s>\n", "lb_ota_update_firmware");
        }

        lb_ota_destroy_params(&ota_data);
    }
    lb_ota_log_info(__FUNCTION__, "</%s>\n", __FUNCTION__);
}

/* ---------------------------------------------------------------------- */
static int32_t
lb_set_params_(NovusOTA *ota_data)
{
    int rc = OTA_OK;

    rc = lb_ota_set_http_data(ota_data, NULL, NULL, 0);

    if (OTA_OK == rc)
    {
        rc = lb_ota_set_auth_data(ota_data, NULL, NULL);
    }

    if (OTA_OK == rc)
    {
        rc = lb_ota_set_ssl_data(ota_data, NULL, 0);
    }

    return OTA_OK;
}
