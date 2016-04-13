/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _MOTOR_H_
#define _MOTOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

//Used for starting the project before feedback
#define MOTOR_SERVO_START_DUTY_CYCLE       768
#define MOTOR_BELT_START_DUTY_CYCLE        1024

//guarantee motors move in order to receive feedback
#define MOTOR_SERVO_MAX_HALL_COUNT      2 
#define MOTOR_SERVO_MAX_ROTATION        3
#define MOTOR_SERVO_MAX_SPEED           1900
#define MOTOR_SERVO_HIGH_SPEED_FACTOR   10
#define MOTOR_SERVO_MIN_SPEED           2100
#define MOTOR_SERVO_LOW_SPEED_FACTOR    10
#define MOTOR_SERVO_MIN_DUTY_CYCLE      768
#define MOTOR_SERVO_MAX_DUTY_CYCLE      2048


#define MOTOR_BELT_MAX_HALL_COUNT      00
#define MOTOR_BELT_MAX_ROTATION        00
#define MOTOR_BELT_MAX_SPEED           255
#define MOTOR_BELT_HIGH_SPEED_FACTOR   10
#define MOTOR_BELT_MIN_SPEED           10000
#define MOTOR_BELT_LOW_SPEED_FACTOR    245
#define MOTOR_BELT_MIN_DUTY_CYCLE     1024
#define MOTOR_BELT_MAX_DUTY_CYCLE     3072


void MOTORS_INIT(void);
void MOTOR_SERVO_HALL_DETECT(void);
void MOTOR_SERVO_CALCULATE_SPEED(void);
uint32_t MOTOR_BELT_HALL_DETECT(void);
void MOTOR_BELT_CALCULATE_SPEED(uint32_t MOTOR_BELT_HALL_COUNT);




#endif
