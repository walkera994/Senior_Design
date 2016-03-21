
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Belt_Motor.h"


void BELT_MOTOR_INITIALIZE(void){
  attachInterrupt((digitalPinToInterrupt(ENCODER_PIN_0)), BELT_MOTOR_ISR, LOW);
  attachInterrupt((digitalPinToInterrupt(ENCODER_PIN_1)), BELT_MOTOR_ISR, LOW);
  attachInterrupt((digitalPinToInterrupt(ENCODER_PIN_2)), BELT_MOTOR_ISR, LOW);
  attachInterrupt((digitalPinToInterrupt(ENCODER_PIN_3)), BELT_MOTOR_ISR, LOW);
}

void BELT_MOTOR_ISR(void){
  if (ENCODER_COUNT == BELT_MOTOR_COUNT_MAX){
    ENCODER_COUNT = 0;
  } else {
  ENCODER_COUNT++;
  }
}

void BELT_MOTOR_PI_INITIALIZE(void){
  LAST_TIME = millis();
  BELT_MOTOR_SPEED = 0;
}

void BELT_MOTOR_SET_PWM(uint8_t DC){
  pinMode(BELT_MOTOR_PIN, OUTPUT);
  analogWriteResolution(BELT_MOTOR_ADC_RESOLUTION);
  analogWrite(BELT_MOTOR_PIN, DC);
}

void BELT_MOTOR_CALCULATE_PI(void){
  //Local cars
  int16_t SPEED_ERROR = 0;
  int16_t P_ERROR = 0;
  int16_t I_ERROR = 0;
  uint16_t TIME_CHANGE = 0;
  uint16_t ROTATION = 0;
  uint16_t ROTATIONAL_VELOCITY = 0;

  //Get time info
  CURRENT_TIME = millis();
  TIME_CHANGE = CURRENT_TIME - LAST_TIME;
  
  //Calculate rotations, rotaional velocity, and then belt speed
  ROTATION = ENCODER_COUNT/BELT_MOTOR_RPM_COUNT; //Encoder count / counts per rotation
  ROTATIONAL_VELOCITY = ROTATION/TIME_CHANGE; //Rotations per second
  BELT_MOTOR_SPEED = ROTATIONAL_VELOCITY*BELT_MOTOR_RATIO; //Ratio of RPS to cm/s

  //Calculate errors
  SPEED_ERROR = BELT_MOTOR_SPEED_SETPOINT - BELT_MOTOR_SPEED;
  P_ERROR = KP * SPEED_ERROR;
  I_ERROR = KI * SPEED_ERROR * TIME_CHANGE;
  BELT_MOTOR_SPEED = BELT_MOTOR_SPEED + I_ERROR + P_ERROR;

  //16 bit number to 8 bit, may only need to be 8 bit to start. 
  BELT_MOTOR_SET_PWM(BELT_MOTOR_SPEED >> 8); //DEBUG THIS***********************************************************
  LAST_TIME = millis();
}

