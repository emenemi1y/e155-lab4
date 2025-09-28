// STM32L432KC_RCC.h
// Header for all RCC functions 

#ifndef STM32L4_RCC_H
#define STM32L4_RCC_H

#include <stdint.h>

// Definitions

#define __IO volatile

// Base addresses
#define RCC_BASE (0x40021000ULL) // ULL = unsigned long long int
#define TIM15_BASE (0x40013C00ULL)
#define TIM16_BASE (0x40014400ULL)

typedef struct
{
  __IO uint32_t CR1;        /*!< TIM15 control register 1,                        Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< TIM15 control register 2,                        Address offset: 0x04 */
  __IO uint32_t SMCR;       /*!< TIM15 slave mode control register,               Address offset: 0x08 */
  __IO uint32_t DIER;       /*!< TIM15 DMA/interrupt enable register,             Address offset: 0x0C */


// PLL
#define PLLSRC_HSI 0
#define PLLSRC_HSE 1