// STM32L432KC_TIM16.c
// Source code for TIM16 functions 

#include "STM32L432KC_TIM16.h"

void initTIM16(void) {
  // Slow clock such that one time unit = 1 Us (assuming 80 MHz clock)
  TIM16->PSC = (uint32_t) (80000000/1e6 - 1);

  // Disable generation of uif for anything other than counter overflow
  TIM16->CR1 |= (1 << 2);
  
  // Generate update event 
  TIM16->EGR |= 1;

  // Enable timer
  TIM16->CR1 |= (1 << 0);

  // Reset uif bit 
  TIM16->SR &= ~(0x1);
}

void delayTIM16 (int val) {

  TIM16->ARR = val;    // Set timer max count
  TIM16->EGR |= 1;     // Force update
  TIM16->SR &= ~(1 << 0); // Clear UIF

  // Wait until ARR value is reached 
  while(!(TIM16->SR & 1));

}

void initDelayTIM16 (int val) {
  TIM16->ARR = val;
  TIM16->EGR |= 1;
  TIM16->SR &= ~(1 << 0);
}

// Get UIF
int getStatusTIM16(void) {
  return (TIM16->SR & 1);

}