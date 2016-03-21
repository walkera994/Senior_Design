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

void SOLENOID_LOGIC_INITIALIZE(void) {
  digitalWrite(SOLENOID_ONE, 0);
  digitalWrite(SOLENOID_TWO, 0);
  digitalWrite(SOLENOID_THREE, 0);
  digitalWrite(SOLENOID_FOUR, 0);
  digitalWrite(SOLENOID_FIVE, 0);

}

