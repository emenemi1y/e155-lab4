// STM32L432KC_TIM15.c
// Source code for TIM15 functions 

#include "STM32L432KC_TIM15.h"

void initTIM15(void) {
  // disable slave mode controller register (to set clock source to CK_INT)
  TIM15->SMCR &= ~(111 << 0);

  // slow clock to 100 kHz
  TIM15->PSC = (uint32_t) 0;
  
  // generate update event 
  TIM15->EGR |= 1;

  // enable timer
  TIM15->CR1 |= (1 << 0);
}

void disableTIM15(void) {
  TIM15->CR1 &= ~(1 << 0);
}

void enableTIM15(void) {
  TIM15->CR1 |= (1 << 0);
  TIM15->SR &= ~(1 << 0);
}

void delayTIM15 (int val) {
  // set value of ARR 
  TIM15->ARR = (uint32_t) (10 * val);

  // wait until clock reaches ARR value 
  // enableTIM15();

  TIM15->EGR |= (1 << 0); // force update
  TIM15->SR &= ~(1 << 0); // reset uif bit
  TIM15->CNT = 0;         // set count to zero

  while(!(getStatusTIM15())) {
    __asm("nop");
  }

  disableTIM15();
}

// get UIF
int getStatusTIM15(void) {
  return ((TIM15->SR >> 0) & 1);

}