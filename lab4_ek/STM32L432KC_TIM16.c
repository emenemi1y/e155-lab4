// STM32L432KC_TIM16.c
// Source code for TIM16 functions 

#include "STM32L432KC_TIM16.h"

void initTIM16 (void) {  
  // enable counter
  TIM16->CR1 |= (1 << 0);

  // slow clock to 100 kHz
  TIM16->PSC = 39;

}

void delay (int val) {
  // set value of ARR 
  TIM16->ARR = (int) 100000 * val;

  // wait until clock reaches ARR value 
}


int getStatusTIM16 (void) {
  return (TIM16->SR >> 0) & 1;
}

