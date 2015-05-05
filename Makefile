CFLAGS=-Os -std=c11 -pedantic -Wall -Wextra -mmcu=atmega328p -DF_CPU=16000000UL
LDFLAGS=-Wl,-O1,-s,--sort-common,--as-needed

all: lib test

lib:
	avr-gcc ${CFLAGS} -c -II2C PCF8574.c -o PCF8574.o

test: lib
	avr-gcc ${CFLAGS} ${LDFLAGS} -II2C I2C/I2C.c PCF8574.c PCF8574_test.c -o PCF8574_test.bin
	avr-objcopy -O ihex PCF8574_test.bin PCF8574_test.hex

flash: test
	avrdude -q -c usbasp -p m8 -U flash:w:PCF8574_test.hex
