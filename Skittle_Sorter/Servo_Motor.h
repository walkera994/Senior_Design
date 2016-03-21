/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

#define SERVO_MOTOR_ADC_RESOLUTION   8    //Must be 8-12 bits. If changed, adjust .cpp accordingly


#endif

