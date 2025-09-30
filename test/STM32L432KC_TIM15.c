// STM32L432KC_TIM15.c
// Source code for TIM15 functions 

#include "STM32L432KC_TIM15.h"

void initTIM15(void) {
  // disable slave mode controller register (to set clock source to CK_INT)
  TIM15->SMCR &= ~(111 << 0);

  // enable timer
  TIM15->CR1 |= (1 << 0);

  // slow clock to 1.25 MHz
  TIM15->PSC = 63;
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
  TIM15->ARR = (int) (1250000 * ((float) val / 1000));

  // wait until clock reaches ARR value 
  enableTIM15();
  while(~(getStatusTIM15())) {
    __asm("nop");
  }
  TIM15->SR &= ~(1 << 0);
  disableTIM15();
}


int getStatusTIM15(void) {
  return (TIM15->SR >> 0) & 1;

}