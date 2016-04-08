/*
 * Skittles.h
 * AUTHOR: A.Chou
 * REV: 0.1.0
 * REQUIRES:
 * MODIFIES:
 * EFFECTS:
 */

#ifndef _SKITTLES_H_
#define _SKITTLES_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Common.h"

class System {
  public:
    System();   // Constructor
    ~System();  // Destructor
    enum COLOR {RED, GREEN, PURPLE, YELLOW, ORANGE};
    static char TIME_TO_RED_BIN;    // NEED TO DEFINE
    static char TIME_TO_GREEN_BIN;  // NEED TO DEFINE
    static char TIME_TO_PURPLE_BIN; // NEED TO DEFINE
    static char TIME_TO_YELLOW_BIN; // NEED TO DEFINE
    static char TIME_TO_ORANGE_BIN; // NEED TO DEFINE
};

class Skittles : public System {
  public:
    void SET_SKITTLE_COLOR(enum COLOR);
    Skittles();   // Constructor...may need to pass params/overload
    ~Skittles();  // Destructor
    
};

class Bins : public System {
    char COLOR;
  public:
    void SET_BIN_COLOR(enum COLOR);
    Bins();   // Constructor
    ~Bins();  // Destructor
};

#endif


