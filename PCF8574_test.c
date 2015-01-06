#include <stdint.h>
#include <util/delay.h>
#include "PCF8574.h"

#define SLAVE 0x20

int main(void){
  while(1){
    pcf8574_port_toggle(SLAVE);
    _delay_ms(500);
  }
}
