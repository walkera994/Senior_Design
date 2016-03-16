#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "FEEDER_MOTOR.h"

void FEEDER_MOTOR_STATE_FORWARD (uint16_t FEEDER_MOTOR_DUTY_CYCLE) {
  digitalWrite(FEEDER_MOTOR_IN_A, HIGH);
  digitalWrite(FEEDER_MOTOR_IN_B, LOW);  
  analogWrite(FEEDER_MOTOR_PWM_PIN, FEEDER_MOTOR_DUTY_CYCLE);
}

void FEEDER_MOTOR_STATE_REVERSE (uint16_t FEEDER_MOTOR_DUTY_CYCLE) {
  digitalWrite(FEEDER_MOTOR_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_IN_B, HIGH);
  analogWrite(FEEDER_MOTOR_PWM_PIN, FEEDER_MOTOR_DUTY_CYCLE);
}

void FEEDER_MOTOR_STATE_BRAKE(void) {
  digitalWrite(FEEDER_MOTOR_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_IN_B, LOW);
  analogWrite(FEEDER_MOTOR_PWM_PIN, 0);
}

void FEEDER_MOTOR_STATE_INITIALIZE(void) {
  pinMode(FEEDER_MOTOR_IN_A, OUTPUT);
  pinMode(FEEDER_MOTOR_IN_B, OUTPUT);
  pinMode(FEEDER_MOTOR_PWM_PIN, OUTPUT);
  pinMode(FEEDER_MOTOR_H_BRIDGE_POWER_PIN, OUTPUT);
  digitalWrite(FEEDER_MOTOR_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_IN_B, LOW);
  analogWrite(FEEDER_MOTOR_PWM_PIN, 0);
  digitalWrite(FEEDER_MOTOR_H_BRIDGE_POWER_PIN, HIGH);
}

void FEEDER_MOTOR_STATE_POWER_OFF(void) {
  digitalWrite(FEEDER_MOTOR_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_IN_B, LOW);
  analogWrite(FEEDER_MOTOR_PWM_PIN, 0);
  digitalWrite(FEEDER_MOTOR_H_BRIDGE_POWER_PIN, LOW);
}

void FEEDER_MOTOR_STATE_READ_CURRENT(void) {
  
}

