#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Feeder_Motor.h"

void FEEDER_MOTOR_STATE_FORWARD (uint16_t FEEDER_MOTOR_DUTY_CYCLE) {
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_A, HIGH);
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_B, LOW);  
  analogWrite(FEEDER_MOTOR_BRIDGE_IN_PWM, FEEDER_MOTOR_DUTY_CYCLE);
}

void FEEDER_MOTOR_STATE_REVERSE (uint16_t FEEDER_MOTOR_DUTY_CYCLE) {
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_B, HIGH);
  analogWrite(FEEDER_MOTOR_BRIDGE_IN_PWM, FEEDER_MOTOR_DUTY_CYCLE);
}


void FEEDER_MOTOR_STATE_INITIALIZE(void) {
  pinMode(FEEDER_MOTOR_BRIDGE_IN_A, OUTPUT);
  pinMode(FEEDER_MOTOR_BRIDGE_IN_B, OUTPUT);
  pinMode(FEEDER_MOTOR_BRIDGE_IN_PWM, OUTPUT);
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_A, LOW);
  digitalWrite(FEEDER_MOTOR_BRIDGE_IN_B, LOW);
  analogWrite(FEEDER_MOTOR_BRIDGE_IN_PWM, 0);
  analogReadResolution(FEEDER_MOTOR_ADC_RESOLUTION);
//  analogReference(DEFAULT);
}

/*
 * Vsense = 160mV/A
 * 12 bit resolution = 256 steps
 * 255 = 3.3V, 0 = 0.0V, Resolution = 3.3V/256 = 12.9mV/step 
 * 12.9mV/step / 160mV/A = 80.5mA/step
 */
uint8_t FEEDER_MOTOR_STATE_READ_CURRENT(void) {
  uint8_t ADC_CURRENT = 0;
  ADC_CURRENT = analogRead(FEEDER_MOTOR_BRIDGE_CS);
  ADC_CURRENT = (ADC_CURRENT / 10) * 8;
  return ADC_CURRENT;
  
  
  
}

