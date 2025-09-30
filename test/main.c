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

// Define macros for constants
#define LED_PIN           5
#define DELAY_DURATION_MS    200

// Function for dummy delay by executing nops
void ms_delay(int ms) {
   while (ms-- > 0) {
      volatile int x=1000;
      while (x-- > 0)
         __asm("nop");
   }
}

int main(void) {
    // Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    RCC->APB2ENR |= (1 << 16); // TIM15 EN
    RCC->APB2ENR |= (1 << 17); // TIM16 EN

    // Turn on clock to GPIOB
    RCC->AHB2ENR |= (1 << 1);

    // Set LED_PIN as output
    pinMode(LED_PIN, GPIO_OUTPUT);

    // Blink LED
    while(1) {
        delayTIM15(DELAY_DURATION_MS);
        //  ms_delay(DELAY_DURATION_MS);
        togglePin(LED_PIN);
    }
    return 0;
}