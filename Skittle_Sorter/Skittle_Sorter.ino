
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>

#include <DueTimer.h>
#include <Servo.h>

#include "Belt_Motor.h"
#include "Color_Sensor.h"
#include "Common.h"
#include "Feeder_Motor.h"
#include "LCD_Display.h"
#include "Photo_Resistor.h"
#include "Solenoid_Logic.h"

uint16_t GREENL;
uint16_t REDL;
uint16_t BLUEL;
uint16_t CLEARL;
uint16_t COUNT = 0;
volatile uint16_t GBL_GREEN = 0;
volatile uint16_t GBL_RED = 0;
volatile uint16_t GBL_BLUE = 0;
volatile uint16_t GBL_CLEAR = 0;
volatile uint16_t GLB_GMIN;
volatile uint16_t GLB_RMIN;
volatile uint16_t GLB_BMIN;
volatile uint16_t GLB_CMIN;
volatile uint16_t GLB_GMAX;
volatile uint16_t GLB_RMAX;
volatile uint16_t GLB_BMAX;
volatile uint16_t GLB_CMAX;
volatile uint16_t REV_COUNT = 0;
volatile uint16_t SEC_COUNT = 0;
volatile uint16_t RPM = 0;
Servo myservo;

void MAIN_ISR()
{
  uint16_t GREEN;
  uint16_t RED;
  uint16_t BLUE;
  uint16_t CLEAR;
  COLOR_SENSOR_READ_COLOR_DATA(&RED, &GREEN, &BLUE, &CLEAR);
  if (GBL_CLEAR == 0) {
  GLB_GMIN = GREEN;
  GLB_RMIN = RED;
  GLB_BMIN = BLUE;
  GLB_CMIN = CLEAR;
  GLB_GMAX = GREEN;
  GLB_RMAX = RED;
  GLB_BMAX = BLUE;
  GLB_CMAX = CLEAR; 
  }
  if (GLB_GMIN > GREEN) GLB_GMIN = GREEN;
  if (GLB_RMIN > RED) GLB_RMIN = RED;
  if (GLB_BMIN > BLUE) GLB_GMIN = BLUE;
  if (GLB_CMIN > CLEAR) GLB_CMIN = CLEAR;
  if (GLB_GMAX < GREEN) GLB_GMAX = GREEN;
  if (GLB_RMAX < RED) GLB_RMAX = RED;
  if (GLB_BMAX < BLUE) GLB_BMAX = BLUE;
  if (GLB_CMAX < CLEAR) GLB_CMAX = CLEAR;
  GBL_GREEN = GREEN;
  GBL_RED = RED;
  GBL_BLUE = BLUE;
  GBL_CLEAR = CLEAR;
  Serial.print("Rmax: "); Serial.print(GLB_RMAX, DEC); Serial.print(" ");
  Serial.print("Gmax: "); Serial.print(GLB_GMAX, DEC); Serial.print(" ");
  Serial.print("Bmax: "); Serial.print(GLB_BMAX, DEC); Serial.print(" ");
  Serial.print("Cmax: "); Serial.print(GLB_CMAX, DEC); Serial.print(" ");
  Serial.println(" ");
  Serial.print("Rmin: "); Serial.print(GLB_RMIN, DEC); Serial.print(" ");
  Serial.print("Gmin: "); Serial.print(GLB_GMIN, DEC); Serial.print(" ");
  Serial.print("Bmin: "); Serial.print(GLB_BMIN, DEC); Serial.print(" ");
  Serial.print("Cmin: "); Serial.print(GLB_CMIN, DEC); Serial.print(" ");
  Serial.println(" ");
  if (SEC_COUNT == 3000) {  // 1 minute
    RPM = REV_COUNT;   // RPM calculation
    SEC_COUNT = 0;
    REV_COUNT = 0;
    Serial.print("RPM = ");
    Serial.println(RPM);
  }
  SEC_COUNT++;
}

void HALL_SENSOR_ISR() {
  REV_COUNT++;    
}

void setup(void) {
  Serial.begin(115200);
  analogReadResolution(8);
  if (COLOR_SENSOR_INITIALIZE() == 0) {
    Serial.println("ERROR");
  }
  Timer6.attachInterrupt(MAIN_ISR).setFrequency(50).start();
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
  myservo.write(180);  
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  //attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_PIN), HALL_SENSOR_ISR, FALLING);
}

void loop(void) {

  
}


