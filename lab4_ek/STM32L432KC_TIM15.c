// STM32L432KC_GPIO.c
// Source code for GPIO functions 

#include "STM32L432KC_TIM15.h"

void initTIM15() {
  // disable slave mode controller register (to set clock source to CK_INT)
  TIM15->SMCR

}

void setPrescaler(int val) {
  TIM15->PSC = val;
}

void setAutoReload(int val) {
  TIM15->ARR = val;
}


void enableCounter(int en) {
  
}

int getStatus() {
  return ((TIM15->
  return ((GPIO->IDR) >> pin) & 1;
}
