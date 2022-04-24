#ifndef __OTA_DATA_H__
#define __OTA_DATA_H__

#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define OK 0
#define ERROR -1

typedef struct ota_data NovusOTA;

int32_t lb_ota_init_params(NovusOTA **ota_data);
void lb_ota_destroy_params(NovusOTA **ota_data);

int32_t lb_ota_set_http_data(NovusOTA *ota_data, const char *url, const char *host, int16_t port);
int32_t lb_ota_set_ssl_data(NovusOTA *ota_data, const char *cert_pem, size_t cert_len);
int32_t lb_ota_set_auth_data(NovusOTA *ota_data, const char *username, const char *password);

#endif /* #ifndef __OTA_DATA_H__ */