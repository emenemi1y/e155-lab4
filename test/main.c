// main.c
// GPIO blink LED with clock configuration
// Josh Brake
// jbrake@hmc.edu
// 9/16/24

// Includes for libraries
#include "STM32L432KC_RCC.h"
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_FLASH.h"
#include "STM32L432KC_TIM15.h"
#include "STM32L432KC_TIM16.h"

// Define macros for constants
#define SPEAKER_PIN 5

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


int main(void) {
    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    RCC->APB2ENR |= (1 << 16); // TIM15 EN
    RCC->APB2ENR |= (1 << 17); // TIM16 EN

    initTIM15();

    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    // Set SPEAKER_PIN as output
    pinMode(SPEAKER_PIN, GPIO_OUTPUT);
    digitalWrite(SPEAKER_PIN, 1);
    
    // Play notes
    int period; // period in ms
    /*
    period = (int) (500000 / notes[0][0]);
    int num = 1000;
    while(1){
      delayTIM15(period);
      togglePin(SPEAKER_PIN);
    }
    */


    //for (int i = 0; i < (sizeof(notes) / sizeof(notes[0])); i++){
    int status;
    for (int i = 0; i < 1; i++){
      initDelayTIM16((int) (notes[i][1]));
      period = (int) (500000 / notes[i][0]);
      status = getStatusTIM16();
      while(!(getStatusTIM16())){
        delayTIM15(period);
        togglePin(SPEAKER_PIN);
        status = getStatusTIM16();
      }
    }

    digitalWrite(SPEAKER_PIN, 0);
    
    return 0;
    
}