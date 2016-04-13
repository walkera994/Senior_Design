/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _FEEDER_MOTOR_H_
#define _FEEDER_MOTOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

#define FEEDER_MOTOR_ADC_RESOLUTION   8    //Must be 8-12 bits. If changed, adjust .cpp accordingly

void FEEDER_MOTOR_STATE_FORWARD (uint16_t FEEDER_MOTOR_DUTY_CYCLE);
void FEEDER_MOTOR_STATE_REVERSE (uint16_t FEEDER_MOTOR_DUTY_CYCLE);
void FEEDER_MOTOR_STATE_INITIALIZE(void);
uint8_t FEEDER_MOTOR_STATE_READ_CURRENT(void);

#endif

