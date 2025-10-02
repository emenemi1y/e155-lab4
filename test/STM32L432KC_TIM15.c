// STM32L432KC_TIM15.c
// Source code for TIM15 functions 

#include "STM32L432KC_TIM15.h"

void initTIM15(void) {
  // Slow clock such that one time unit = 1 Us (assuming 80 MHz clock)
  TIM15->PSC = (uint32_t) (80000000/1e6 - 1);

  // Disable generation of uif for anything other than counter overflow
  TIM15->CR1 |= (1 << 2);
  
  // Generate update event 
  TIM15->EGR |= 1;

  // Enable timer
  TIM15->CR1 |= (1 << 0);

  // Reset uif bit 
  TIM15->SR &= ~(0x1);
}

void delayTIM15 (int val) {

  TIM15->ARR = val;    // Set timer max count
  TIM15->EGR |= 1;     // Force update
  TIM15->SR &= ~(0x1); // Clear UIF

  // Wait until ARR value is reached 
  while(!(TIM15->SR & 1));

}

// Get UIF
int getStatusTIM15(void) {
  return (TIM15->SR & 1);

}