// main.x
// E155 Lab 4 
// Emily Kendrick
// ekendrick@hmc.edu
// 9/28/25

// Includes for libraries 
#include "STM32L432KC_RCC.h"
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_TIM15.h"
#include "STM32L432KC_TIM16.h"

// Define macros for constants

#define SPEAKER_PIN        3 // change later


void initTIM(int timer)
{
  // enable the timer 
  // 
}



void delay_millis(TIM_TypeDef * TIMx, uint32_t ms);

void initPWM(int freq, int dur)





int main(void) {
  // Turn on clock to GPIOB
  RCC->AHB2ENR |= (1 << 1);
  RCC->APB2ENR |= (1 << 16); // TIM15 EN
  RCC->APB2ENR |= (1 << 17); // TIM16 EN
  RCC->AHB1ENR |= (1 << 1); // ask about this? 

  // set SPEAKER_PIN as output
  pinMode(SPEAKER_PIN, GPIO_OUTPUT);

  // disable slave mode controller register (to set clock source to CK_INT)

