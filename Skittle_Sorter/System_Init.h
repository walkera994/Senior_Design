#ifndef _SYSTEM_INIT_H_
#define _SYSTEM_INIT_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"
#include "Color_Sensor.h"
#include <Wire.h>

void System_Init(void);

#endif
