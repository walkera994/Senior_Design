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

boolean PHOTO_RESISTOR_READ(uint8_t COLOR){
  uint8_t LIGHT_READ_VALUE = 0;
  LIGHT_READ_VALUE = analogRead(COLOR);
  if (LIGHT_READ_VALUE > 128) {
  return true;
  } else {
  return false;
  }
}


