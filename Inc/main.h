/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

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

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
