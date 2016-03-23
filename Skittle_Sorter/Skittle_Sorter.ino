#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Common.h"
#include "Belt_Motor.h"
#include "Color_Sensor.h"
#include "Feeder_Motor.h"
#include "LCD_Display.h"
#include "Solenoid_Logic.h"

void setup() {
  FEEDER_MOTOR_STATE_INITIALIZE();
  BELT_MOTOR_PI_INITIALIZE();
  COLOR_SENSOR_INITIALIZE();
  SOLENOID_LOGIC_INITIALIZE();
  //LCD_DISPLAY_INITIALIZE();
}

void loop() {
  //BELT_MOTOR_CALCULATE_PI();
  BELT_MOTOR_SET_PWM(0xFF);
}
