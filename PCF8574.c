#include <stdint.h>
#include <util/delay.h>
#include "PCF8574.h"
#include "I2C/I2C.h"

static uint8_t port = 0;

uint8_t pcf8574_port_read(uint8_t addr){
  uint8_t temp;
  
  i2c_start();
  i2c_write((addr << 1) | PCF8574_READ);
  temp = i2c_read(I2C_ACK);
  i2c_stop();

  return temp;
}

void pcf8574_port_write(uint8_t addr, uint8_t state){
  port = state;
  i2c_start();
  i2c_write((addr << 1) | PCF8574_WRITE);
  i2c_write(port);
  i2c_stop();
}
    
void pcf8574_port_toggle(uint8_t addr){
  pcf8574_port_write(addr, (port ^ 0xFF));
}

void pcf8574_port_blink(uint8_t addr){
  pcf8574_port_write(addr, 0xFF);
  _delay_ms(1);
  pcf8574_port_write(addr, 0x00);
}


uint8_t pcf8574_pin_read(uint8_t addr, uint8_t pin){
  return ((pcf8574_port_read(addr) >> pin) & 1);
}

void pcf8574_pin_on(uint8_t addr, uint8_t pin){
  pcf8574_port_write(addr, (port | (1 << pin)));
}

void pcf8574_pin_off(uint8_t addr, uint8_t pin){
  pcf8574_port_write(addr, (port & ~(1 << pin)));
}
  
void pcf8574_pin_toggle(uint8_t addr, uint8_t pin){
  pcf8574_port_write(addr, (port ^ (1 << pin)));
}

void pcf8574_pin_blink(uint8_t addr, uint8_t pin){
  pcf8574_pin_on(addr, pin);
  _delay_ms(1);
  pcf8574_pin_off(addr, pin);
}
