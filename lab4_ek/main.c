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
#include "STM32L432KC_FLASH.h"
#include "STM32L432KC_FLASH.h"

#define SPEAKER_PIN 5;

const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

void ms_delay(int ms) {
  while (ms-- > 0) { 
    volatile int x = 1000;
    while (x-- > 0)
      __asm("nop");
  }
}

/*
int main(void) {

  // Configure flash to add waitstates to avoid timing errors
  configureFlash();

  // Setup the PLL and switch clock source to the PLL
  configureClock(); 
  // Turn on clock to GPIOB
  RCC->AHB2ENR |= (1 << 1);
  // RCC->APB2ENR |= (1 << 16); // TIM15 EN
  // RCC->APB2ENR |= (1 << 17); // TIM16 EN

  // set SPEAKER_PIN as output
  pinMode(SPEAKER_PIN, GPIO_OUTPUT);
  
  
  while(1) { 
    ms_delay(100);
    // togglePin(SPEAKER_PIN);
    digitalWrite(SPEAKER_PIN, 1);
    ms_delay(100);
    digitalWrite(SPEAKER_PIN, 0);
  }
  
  
  // iterate through notes and delays 
  
  for(int i = 0; i < sizeof(notes); i++){
    enableTIM16();
    setARR16((int) (1 / ((float) 2 * notes[i][1]) * 100000));
      while(~getStatusTIM16()){
        if (notes[i][0] == 0) {
          digitalWrite(SPEAKER_PIN, 0);
        }
        else{
          delayTIM15((int) ((float) 1 / notes[i][0] * 1000));
          togglePin(SPEAKER_PIN);
        }

      }

    disableTIM16(); // reset timer
  }
  

}

*/

int main(void) {
    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    // Enable timers 
    RCC->APB2ENR |= (1 << 16); // TIM15 enable
    RCC->APB2ENR |= (1 << 17); // TIM16 enable

    // Set SPEAKER_PIN as output
    GPIO->MODER |= (0b01 << 10);

    // Timer configuration:
    initTIM15();

    // Enable PWM output
    TIM15->CCMR1 |= (0b110 << 4); // OC1M

    TIM15->BDTR |= (1 << 15); // Set MOE

    TIM15->CCER |= (1 << 0); // Capture/Compare 1 output enable

    TIM15->CR1 |= (1 << 7); // ARPE bit in CR1

    TIM15->CCER |= (1 << 0); // CC1 output enable
    TIM15->CCER |= (1 << 2); // CC1 complementary output enable 

    TIM15->ARR = 19999;
    TIM15->CCR1 = 9999;
    
    TIM15->EGR |= (1 << 0); // Reset registers by setting update bit 



    // Blink LED
    /*
    while(1) {
        ms_delay(200);
        togglePin(3);
    }
    */

    while(1) {
      ms_delay(100);
    }

    return 0;
}