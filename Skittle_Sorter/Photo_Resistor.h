/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _PHOTO_RESISTOR_H_
#define _PHOTO_RESISTOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

boolean PHOTO_RESISTOR_READ(uint8_t COLOR);

#endif
