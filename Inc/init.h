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
#define ERROR_LED_Pin GPIO_PIN_13
#define ERROR_LED_GPIO_Port GPIOC

#define TX_LED_Pin GPIO_PIN_14
#define TX_LED_GPIO_Port GPIOC



#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB

#define SPI2_NSS_Pin GPIO_PIN_12
#define SPI2_NSS_GPIO_Port GPIOB



#define UNDER_3V3_Pin GPIO_PIN_9
#define UNDER_3V3_GPIO_Port GPIOC

#define UNDER_5V_Pin GPIO_PIN_8
#define UNDER_5V_GPIO_Port GPIOA

#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA

#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA

#define GPIO_1_Pin GPIO_PIN_15
#define GPIO_1_GPIO_Port GPIOA

#define GPIO_2_Pin GPIO_PIN_10
#define GPIO_2_GPIO_Port GPIOC

#define GPIO_3_Pin GPIO_PIN_11
#define GPIO_3_GPIO_Port GPIOC

#define GPIO_4_Pin GPIO_PIN_12
#define GPIO_4_GPIO_Port GPIOC

#define GPIO_5_Pin GPIO_PIN_11
#define GPIO_5_GPIO_Port GPIOB



/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Function prototypes
 */
void SystemClock_Config(void);
void MX_GPIO_Init(void);

void MX_USART1_UART_Init(void);

void _Error_Handler(char *file, int line);

/* ---------------------------------------------------------------------------
 * Private variables ---------------------------------------------------------
 */




UART_HandleTypeDef uart1;
