// STM32L432KC_TIM16.c
// Source code for TIM16 functions 

#include "STM32L432KC_TIM16.h"

void initTIM16() {  
  // enable counter
  TIM16->CR1 |= (1 << 0);

}

void setPrescaler(int val) {
  TIM16->PSC = val;
}

void setAutoReload(int val) {
  TIM16->ARR = val;
}


int getStatusTIM16() {
  return (TIM16->SR >> 0) & 1;
}

