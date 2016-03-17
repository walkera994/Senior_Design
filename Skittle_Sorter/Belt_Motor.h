/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _BELT_MOTOR_H_
#define _BELT_MOTOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"
#include <PID_v1.h>

#define BELT_MOTOR_ADC_RESOLUTION   8    //Must be 8-12 bits. If changed, adjust .cpp accordingly

void BELT_MOTOR_INITIALIZE(void);
void BELT_MOTOR_ISR(void);
void BELT_MOTOR_PID_INITIALIZE(void);
void BELT_MOTOR_CALCULATE_SPEED(uint8_t TIME);
void BELT_MOTOR_SET_PWM(uint8_t DC);
void BELT_MOTOR_CALCULATE_PID(uint8_t CURRENT_SPEED);


#endif

