#include <PID_v1.h>


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
  
}

void BELT_MOTOR_PID_INITIALIZE(void){
  

}

void BELT_MOTOR_CALCULATE_SPEED(uint8_t TIME){
  
}

void BELT_MOTOR_SET_PWM(uint8_t DC){
  pinMode(BELT_MOTOR_PIN, OUTPUT);
  analogWriteResolution(BELT_MOTOR_ADC_RESOLUTION);
  analogWrite(BELT_MOTOR_PIN, DC);
}

void BELT_MOTOR_CALCULATE_PID(uint8_t CURRENT_SPEED){

}

