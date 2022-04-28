# Baa tchê!


## GETTING STARTED
-----------------

```shell script
get_idf         #alias get_idf='. $HOME/esp/esp-idf/export.sh'
```

### Configure partitions

- Enable `Custom partition table CSV` in `idf.py menuconfig`

### Build

- `idf.py build`

### Configure sdk

- If not using HTTPS, add the following line below `ESP HTTPS OTA` in `sdkconfig`, and build again:
`CONFIG_OTA_ALLOW_HTTP=y`
