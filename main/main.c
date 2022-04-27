#include "ota_log.h"
#include "ota.h"

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------------------- */
void app_main(void)
{
    HTTP http_data = {
        .url = "",
    };

    lb_ota_update_firmware_perform(&http_data, NULL, NULL);
}