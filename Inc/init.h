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

#define G5_IRQ_Pin GPIO_PIN_1
#define G5_IRQ_GPIO_Port GPIOC

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

#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB

#define G3_COMMS_Pin GPIO_PIN_10
#define G3_COMMS_GPIO_Port GPIOB

#define SPI2_NSS_Pin GPIO_PIN_12
#define SPI2_NSS_GPIO_Port GPIOB

#define LIN_ENABLE12_Pin GPIO_PIN_6
#define LIN_ENABLE12_GPIO_Port GPIOC

#define LIN_ENABLE34_Pin GPIO_PIN_7
#define LIN_ENABLE34_GPIO_Port GPIOC

#define LIN_ENABLE56_Pin GPIO_PIN_8
#define LIN_ENABLE56_GPIO_Port GPIOC

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
 * Function prototypes
 */
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_SPI1_Init(void);
void MX_USART1_UART_Init(void);
void MX_DAC_Init(void);
void MX_SPI2_Init(void);

/* ---------------------------------------------------------------------------
 * Private variables ---------------------------------------------------------
 */
DAC_HandleTypeDef dac;

SPI_HandleTypeDef spi1;
SPI_HandleTypeDef spi2;

UART_HandleTypeDef uart1;
