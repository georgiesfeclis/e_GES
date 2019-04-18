/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN2_INIT_H_
#define GEN2_INIT_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include "stm32f4xx_hal.h"
/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */
#define LIN_IRQ4_Pin GPIO_PIN_4
#define LIN_IRQ4_GPIO_Port GPIOC
#define LIN_IRQ4_EXTI_IRQn EXTI4_IRQn

#define LIN_IRQ3_Pin GPIO_PIN_5
#define LIN_IRQ3_GPIO_Port GPIOC
#define LIN_IRQ3_EXTI_IRQn EXTI9_5_IRQn

#define LIN_IRQ2_Pin GPIO_PIN_0
#define LIN_IRQ2_GPIO_Port GPIOB
#define LIN_IRQ2_EXTI_IRQn EXTI0_IRQn

#define LIN_IRQ1_Pin GPIO_PIN_1
#define LIN_IRQ1_GPIO_Port GPIOB
#define LIN_IRQ1_EXTI_IRQn EXTI1_IRQn

#define LIN_ENABLE12_Pin GPIO_PIN_6
#define LIN_ENABLE12_GPIO_Port GPIOC

#define LIN_ENABLE34_Pin GPIO_PIN_7
#define LIN_ENABLE34_GPIO_Port GPIOC

#define LIN_ENABLE56_Pin GPIO_PIN_8
#define LIN_ENABLE56_GPIO_Port GPIOC

#define SLAVE_SELECT1_Pin GPIO_PIN_4
#define SLAVE_SELECT1_GPIO_Port GPIOB

#define SLAVE_SELECT2_Pin GPIO_PIN_5
#define SLAVE_SELECT2_GPIO_Port GPIOB

#define SLAVE_SELECT3_Pin GPIO_PIN_6
#define SLAVE_SELECT3_GPIO_Port GPIOB

#define SLAVE_SELECT4_Pin GPIO_PIN_7
#define SLAVE_SELECT4_GPIO_Port GPIOB

#define SLAVE_SELECT5_Pin GPIO_PIN_8
#define SLAVE_SELECT5_GPIO_Port GPIOB

#define SLAVE_SELECT6_Pin GPIO_PIN_9
#define SLAVE_SELECT6_GPIO_Port GPIOB
/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
/*
 *  Initialise gen2 peripherals
 */
void gen2_periph_init(void);
/* ----------------------------------------------------------------------------*/

/*
 * De-Init gen2 peripherals
 */
void gen2_periph_deinit(void);
/* ----------------------------------------------------------------------------*/

/*
 * Enable Gen2 interrupt lines and set priority
 */
void enable_gen2_interrupts(void);
/* ----------------------------------------------------------------------------*/

/*
 * Disable Gen2 interrupt lines
 */
void disable_gen2_interrupts(void);
/* ----------------------------------------------------------------------------*/

/*
 * Initialise GPIOs used for Gen 2 comms
 */
void gen2_GPIOs_init(void);
/* ----------------------------------------------------------------------------*/

/*
 * Initialise SPI2 Driver
 */
void SPI2_Init(void);
/* ----------------------------------------------------------------------------*/


#endif /* GEN2_INIT_H_ */
