/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _COLOR_SENSOR_H_
#define _COLOR_SENSOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

void FEEDER_MOTOR_STATE_INITIALIZE   (void);
void FEEDER_MOTOR_STATE_POWER_OFF    (void);
void FEEDER_MOTOR_STATE_FORWARD      (uint16_t FEEDER_MOTOR_DUTY_CYCLE);
void FEEDER_MOTOR_STATE_REVERSE      (uint16_t FEEDER_MOTOR_DUTY_CYCLE);
void FEEDER_MOTOR_STATE_BRAKE        (void);
void FEEDER_MOTOR_CURRENT_SENSE      (void);

