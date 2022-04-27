#include "ota_log.h"
#include "ota.h"

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------------------- */
void app_main(void)
{
    int rc = lb_ota_update_firmware_perform(NULL, NULL, NULL);

    lb_ota_update_firmware_finish(rc);
}
