/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi-line overview here if useful.
 */


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

/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Function prototypes
 */
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_SPI1_Init(void);
void MX_USART1_UART_Init(void);

/* ---------------------------------------------------------------------------
 * Private variables ---------------------------------------------------------
 */
SPI_HandleTypeDef spi1;
UART_HandleTypeDef uart1;
