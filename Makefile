CFLAGS=-Os -std=c99 -pedantic -mmcu=atmega8a -DF_CPU=8000000UL

all: bin hex

bin:
	avr-gcc ${CFLAGS} -II2C I2C/I2C.c PCF8574.c PCF8574_test.c -o PCF8574_test.bin

hex:
	avr-objcopy -O ihex PCF8574_test.bin PCF8574_test.hex

flash:
	avrdude -c usbasp -p m8 -U flash:w:PCF8574_test.hex
