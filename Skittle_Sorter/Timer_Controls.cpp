/*
  FreqPeriodDue 
  
  
  Based loosely on the FreqPeriod library at:
  Martin Nawrath KHM LAB3
  Kunsthochschule f�r Medien K�ln
  Academy of Media Arts
  http://www.khm.de
  http://interface.khm.de/index.php/labor/experimente/  
*/

#include "Timer_Controls.h"

void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency) {
       pmc_set_writeprotect(false);
       pmc_enable_periph_clk((uint32_t)irq);
       TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4);
       uint32_t rc = VARIANT_MCK/1/frequency; //128 because we selected TIMER_CLOCK4 above
       TC_SetRA(tc, channel, rc/2); //50% high, 50% low
       TC_SetRC(tc, channel, rc);
       TC_Start(tc, channel);
       tc->TC_CHANNEL[channel].TC_IER=TC_IER_CPCS;
       tc->TC_CHANNEL[channel].TC_IDR=~TC_IER_CPCS;
       NVIC_EnableIRQ(irq);
}




