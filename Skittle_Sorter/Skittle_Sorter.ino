#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Common.h"


void setup() {
FEEDER_MOTOR_STATE_INITIALIZE();
BELT_MOTOR_PI_INITIALIZE();
COLOR_SENSOR_INITIALIZE();
SOLENOID_LOGIC_INITIALIZE();
//LCD_DISPLAY_INITIALIZE();
}

void loop() {

}
