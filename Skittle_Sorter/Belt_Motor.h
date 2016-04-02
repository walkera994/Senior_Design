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




#define BELT_MOTOR_RATIO    100 //Ratio of RPMs and linear velocity ie 1 RPM = 10cm/s
#define BELT_MOTOR_RPM_COUNT        466
#define BELT_MOTOR_ADC_RESOLUTION   8    //Must be 8-12 bits. If changed, adjust .cpp accordingly
#define BELT_MOTOR_COUNT_MAX        255
#define BELT_MOTOR_SPEED_SETPOINT   200
#define KP                          1
#define KI                          1

void BELT_MOTOR_INITIALIZE(void);
void BELT_MOTOR_ISR(void);
void BELT_MOTOR_PI_INITIALIZE(void);
void BELT_MOTOR_SET_PWM(uint8_t DC);
void BELT_MOTOR_CALCULATE_PI(void);

#endif

