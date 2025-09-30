// STM32L432KC_TIM16.c
// Source code for TIM16 functions 

#include "STM32L432KC_TIM16.h"

void initTIM16 (void) {  
  // enable counter
  TIM16->CR1 |= (1 << 0);

  // slow clock to 100 kHz
  TIM16->PSC = 39;

}

// val in ms
void delayTIM16 (int val) {
  // set value of ARR 
  TIM16->ARR = (int) 100000 * (int) ((float) val / 1000);

  // wait until clock reaches ARR value 
  TIM16->CR1 |= (1 << 0);
  while(~((TIM16-> SR >> 0) & 1)) {
    __asm("nop");
  }
}

void disableTIM16(void) {
  TIM16->CR1 &= ~(1 << 0);
}

void enableTIM16(void) {
  TIM16->CR1 |= (1 << 0);
}

void setARR16(int val) {
  TIM16->ARR = val;
}


int getStatusTIM16 (void) {
  return (TIM16->SR >> 0) & 1;
}

