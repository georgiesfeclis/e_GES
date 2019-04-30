/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_INIT_H_
#define GEN5_INIT_H_

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
#define G5_IRQ_Pin GPIO_PIN_1
#define G5_IRQ_GPIO_Port GPIOC
/* ---------------------------------------------------------------------------
 * Types
 */
SPI_HandleTypeDef spi1;
/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Initialise G5 peripherals
 */
void gen5_periph_init(void);
/* ---------------------------------------------------------------------------*/

/*
 * De-Initialise G5 peripherals
 */
void gen5_periph_deinit(void);
/* ---------------------------------------------------------------------------*/

/*
 * Inisialise SPI1 driver
 */
void SPI1_Init(void);
/* ---------------------------------------------------------------------------*/

/*
 * Initialise GPIOs used for Gen5
 */
void G5_IRQ_Pin_Init(void);
/* ---------------------------------------------------------------------------*/

#endif /* GEN5_INIT_H_ */
