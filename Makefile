CFLAGS=-Os -std=c99 -pedantic -mmcu=atmega8a -DF_CPU=8000000UL

all: lib test

lib:
	avr-gcc ${CFLAGS} -c -II2C I2C/I2C.o PCF8574.c -o PCF8574.o

test: lib
	avr-gcc ${CFLAGS} I2C/I2C.o PCF8574.o PCF8574_test.c -o PCF8574_test.bin
	avr-objcopy -O ihex PCF8574_test.bin PCF8574_test.hex

flash: test
	avrdude -c usbasp -p m8 -U flash:w:PCF8574_test.hex
