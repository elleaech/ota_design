# Baa tchê!


## GETTING STARTED
-----------------

```shell script
alias get_idf='. $HOME/esp/esp-idf/export.sh
get_idf
```

### SDK Configurations

- Enable `Partition Table -> Partition Table -> Custom partition table CSV` in `idf.py menuconfig`
- Enable `Component config -> ESP HTTPS OTA -> Allow HTTP for OTA` in `idf.py menuconfig` (for tests only)

### Build

- `idf.py build`

#### Using VSCode extension

`F1 -> ESP-IDF: Build, Flash and start a monitor on your device`
