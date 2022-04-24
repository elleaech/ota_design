LIBS_INCLUDE = -I./
TARGET = ota

main:
	@gcc -o main.bin main.c $(TARGET).c $(LIBS_INCLUDE)
clean:
	rm *.bin