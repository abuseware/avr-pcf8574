#include <stdint.h>
#include <util/delay.h>

#include <I2C.h>
#include "PCF8574.h"

PCF8574 *slave;

int main(void){
  i2c_speed(FAST);
  slave = pcf8574_init(0x20);
  
  while(1){
    pcf8574_port_toggle(slave);
    _delay_ms(500);
  }

  pcf8574_free(slave);
}
