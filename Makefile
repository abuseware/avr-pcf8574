CFLAGS=-Os -std=c99 -pedantic -Wall -Wextra -mmcu=atmega8a -DF_CPU=8000000UL
LDFLAGS=-Wl,-O1,-s,--sort-common,--as-needed

all: lib test

lib:
	avr-gcc ${CFLAGS} -c -II2C PCF8574.c -o PCF8574.o

test: lib
	avr-gcc ${CFLAGS} ${LDFLAGS} I2C/I2C.o PCF8574.o PCF8574_test.c -o PCF8574_test.bin
	avr-objcopy -O ihex PCF8574_test.bin PCF8574_test.hex

flash: test
	avrdude -q -c usbasp -p m8 -U flash:w:PCF8574_test.hex
