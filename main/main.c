#include "ota_log.h"
#include "ota.h"

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------------------- */
void app_main(void)
{
    lb_ota_log_info(__FUNCTION__, "<%s>\n", __FUNCTION__);

    int rc = lb_ota_update_firmware_perform(NULL, NULL, NULL);

    lb_ota_update_firmware_finish(rc);

    lb_ota_log_info(__FUNCTION__, "</%s>\n", __FUNCTION__);
}
