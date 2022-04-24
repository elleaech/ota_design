#include "ota_data.h"
#include "ota.h"

#include <stdio.h>
#include <stdlib.h>

static int32_t lb_set_params_(NovusOTA *ota_data);

/* ---------------------------------------------------------------------- */
int main(int argc, char **argv)
{
    int rc = OK;

    NovusOTA *ota_data = NULL;

    rc = lb_ota_init_params(&ota_data);

    if (OK == rc && NULL != ota_data)
    {
        rc = lb_set_params_(ota_data);

        if (OK == rc)
        {
            lb_ota_update_firmware(ota_data);
        }

        lb_ota_destroy_params(&ota_data);
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
static int32_t
lb_set_params_(NovusOTA *ota_data)
{
    int rc = OK;

    rc = lb_ota_set_http_data(ota_data, NULL, NULL, 0);

    if (OK == rc)
    {
        rc = lb_ota_set_auth_data(ota_data, NULL, NULL);
    }

    if (OK == rc)
    {
        rc = lb_ota_set_ssl_data(ota_data, NULL, 0);
    }

    return rc;
}
