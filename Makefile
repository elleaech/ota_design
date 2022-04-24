SOURCE_DIR = ota
MAIN_DIR = main

LIBS_INCLUDE = -I$(SOURCE_DIR)

TARGETS = $(MAIN_DIR)/main.c $(SOURCE_DIR)/ota.c $(SOURCE_DIR)/ota_data.c


default:
	@gcc -o main.bin $(TARGETS) $(LIBS_INCLUDE)

clean:
	rm *.bin
