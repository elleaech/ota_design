#ifndef __OTA_TEMPLATE_H__
#define __OTA_TEMPLATE_H__

#include "ota_data.h"

int32_t lb_ota_begin(void);
int32_t lb_ota_perform(void);
int32_t lb_ota_is_complete_data_received(void);
int32_t lb_ota_get_img_desc(void);
int32_t lb_ota_finish(void);

#endif /* #ifndef __OTA_TEMPLATE_H__ */
