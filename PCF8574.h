#pragma once

#define PCF8574_WRITE 0
#define PCF8574_READ 1

#define PCF8574_PIN_ON 1
#define PCF8574_PIN_OFF 0

uint8_t pcf8574_port_read(uint8_t addr);
void pcf8574_port_write(uint8_t addr, uint8_t state);
void pcf8574_port_toggle(uint8_t addr);

uint8_t pcf8574_pin_read(uint8_t addr, uint8_t pin);
void pcf8574_pin_on(uint8_t addr, uint8_t pin);
void pcf8574_pin_off(uint8_t addr, uint8_t pin);
void pcf8574_pin_toggle(uint8_t addr, uint8_t pin);
