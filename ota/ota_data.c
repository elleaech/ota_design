#include "ota_data.h"
#include "ota.h"

/********************
 *    STRUCTS
 ********************/
struct http_data
{
    const char *url;
    const char *host;
    int16_t port;
};

struct auth_data
{
    const char *username;
    const char *password;
};

struct ssl_data
{
    const char *cert_pem;
    size_t cert_len;
};

struct ota_data
{
    struct http_data http;
    struct auth_data auth;
    struct ssl_data ssl;
};

/********************
 *    DEFINES
 ********************/
#define OTA_DATA_SIZE sizeof(struct ota_data)

/********************
 *  DATA FUNCTIONS
 ********************/
/* ---------------------------------------------------------------------- */
int32_t
lb_ota_init_params(NovusOTA **ota_data)
{
    int32_t rc = OK;

    if (NULL != ota_data)
    {
        *ota_data = malloc(OTA_DATA_SIZE);

        if (NULL != *ota_data)
        {
            memset(*ota_data, 0x00, OTA_DATA_SIZE);
        }
        else
        {
            rc = ERROR;
        }
    }
    else
    {
        rc = ERROR;
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_set_http_data(NovusOTA *ota_data, const char *url, const char *host, int16_t port)
{
    int32_t rc = OK;

    if (NULL != ota_data && NULL != url && NULL != host)
    {
        ota_data->http.url = url;
        ota_data->http.host = host;
        ota_data->http.port = port;
    }
    else
    {
        rc = ERROR;
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_set_ssl_data(NovusOTA *ota_data, const char *cert_pem, size_t cert_len)
{
    int32_t rc = OK;

    if (NULL != ota_data && NULL != cert_pem)
    {
        ota_data->ssl.cert_pem = cert_pem;
        ota_data->ssl.cert_len = cert_len;
    }
    else
    {
        rc = ERROR;
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
int32_t
lb_ota_set_auth_data(NovusOTA *ota_data, const char *username, const char *password)
{
    int32_t rc = OK;

    if (NULL != ota_data && NULL != username && NULL != password)
    {
        ota_data->auth.password = password;
        ota_data->auth.username = username;
    }
    else
    {
        rc = ERROR;
    }

    return rc;
}

/* ---------------------------------------------------------------------- */
void lb_ota_destroy_params(NovusOTA **ota_data)
{
    if (NULL != ota_data && NULL != *ota_data)
    {
        free(*ota_data);
        *ota_data = NULL;
    }
}

/********************
 *  OTA FUNCTIONS
 ********************/
/* ---------------------------------------------------------------------- */
int32_t
lb_ota_update_firmware(NovusOTA *ota_data)
{
    int32_t rc = OK;

    if (NULL != ota_data)
    {
        lb_ota_begin();

        if (OK == rc)
        {
            lb_ota_perform();
        }

        if (OK == rc)
        {
            lb_ota_is_complete_data_received();
        }

        if (OK == rc)
        {
            lb_ota_get_img_desc();
        }

        if (OK == rc)
        {
            lb_ota_finish();
        }
    }

    return rc;
}
