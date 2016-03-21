#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Photo_Resistor.h"

boolean PHOTO_RESISTOR_READ(uint8_t COLOR){
  uint8_t LIGHT_READ_VALUE = 0;
  LIGHT_READ_VALUE = analogRead(COLOR);
  if (LIGHT_READ_VALUE > 128) {
  return true;
  } else {
  return false;
  }
}

