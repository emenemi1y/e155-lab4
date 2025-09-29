// STM32L432KC_TIM15.c
// Source code for TIM15 functions 

#include "STM32L432KC_TIM15.h"

void initTIM15(void) {
  // disable slave mode controller register (to set clock source to CK_INT)
  TIM15->SMCR &= ~(111 << 0);

  // enable timer
  TIM15->CR1 |= (1 << 0);

  // enable PWM mode 1
  /*
  TIM15->CCMR1 &= ~(1 << 4);
  TIM15->CCMR1 |= (1 << 5);
  TIM15->CCMR1 |= (1 << 6);
  */
}


/*
void enablePWM(int f){
  // set frequency in arr 
  // if clock is 4 MHz

  int arr_val = (int) 4000000 / f; // number of clock cycles per period 
  int dc = (int) arr_val / 2;      // duty cycle

  TIM15->ARR = arr_val;
  TIM15->CCR1 = dc;

}
*/


int getStatusTIM15(void) {
  return (TIM15->SR >> 0) & 1;

}
