/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef UART_ISR_H_
#define UART_ISR_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include "stm32f4xx_hal.h"
#include <stdint.h>

/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */
#define ASCII_ENTER ((uint8_t) 13)
/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */
//uint8_t RxBuffer[20];
//uint8_t RxData;

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Initialise UART ISR
 */
void uart_isr_init(void);


#endif /* UART_ISR_H_ */
