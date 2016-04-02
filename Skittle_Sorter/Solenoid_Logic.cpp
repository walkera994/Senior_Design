#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Solenoid_Logic.h"

void SOLENOID_LOGIC_ACTUATE_SOLENOID(uint8_t SOLENOID_NUMBER) {
  digitalWrite(SOLENOID_NUMBER, (!digitalRead(SOLENOID_NUMBER)));
}

