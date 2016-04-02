/*
  FreqPeriodDue.h
  
  Based loosely on the FreqPeriod library from:
  FreqPeriod.h - Library for a Frequency Measurement c.
  Created by Martin Nawrath, KHM Lab3, June. 2010
  Released into the public domain.
*/

#ifndef _TIMER_CONTROLS_H_
#define _TIMER_CONTROLS_H_

#include <stdint.h>
#include "Arduino.h"

void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency);

/*
Example Call
startTimer(TC1, 0, TC3_IRQn, 4); 
*/
#endif

/*
ISR/IRQ   TC      Channel     Due pins
TC0       TC0     0           2, 13
TC1       TC0     1           60, 61
TC2       TC0     2           58
TC3       TC1     0           none  
TC4       TC1     1           none
TC5       TC1     2           none
TC6       TC2     0           4, 5
TC7       TC2     1           3, 10
TC8       TC2     2           11, 12


TC  Chan    NVIC "irq"    IRQ handler function    PMC id
TC0 0       TC0_IRQn      TC0_Handler             ID_TC0
TC0 1       TC1_IRQn      TC1_Handler             ID_TC1
TC0 2       TC2_IRQn      TC2_Handler             ID_TC2
TC1 0       TC3_IRQn      TC3_Handler             ID_TC3
TC1 1       TC4_IRQn      TC4_Handler             ID_TC4
TC1 2       TC5_IRQn      TC5_Handler             ID_TC5
TC2 0       TC6_IRQn      TC6_Handler             ID_TC6
TC2 1       TC7_IRQn      TC7_Handler             ID_TC7
TC2 2       TC8_IRQn      TC8_Handler             ID_TC8

 */



