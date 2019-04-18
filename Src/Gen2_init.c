/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */


/* ----------------------------------------------------------------------------
 * Implements
 */
#include "Gen2_init.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "init.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
SPI_HandleTypeDef spi2;
/* ----------------------------------------------------------------------------
 * Private defines
 */

/* ----------------------------------------------------------------------------
 * Private macros
 */

/* ----------------------------------------------------------------------------
 * Private variables 
 */

/* ----------------------------------------------------------------------------
 * Private functions
 */

/* ----------------------------------------------------------------------------
 * Public variables
 */

/* ----------------------------------------------------------------------------
 * Public functions
 */

/* ----------------------------------------------------------------------------*/
void gen2_periph_init(void)
{
	SPI2_Init();
	gen2_GPIOs_init();
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void gen2_periph_deinit(void)
{
	gen2_GPIOs_init();
	HAL_SPI_DeInit(&spi2);
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void gen2_GPIOs_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, LIN_ENABLE12_Pin|LIN_ENABLE34_Pin|LIN_ENABLE56_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, SLAVE_SELECT1_Pin|SLAVE_SELECT2_Pin|SLAVE_SELECT3_Pin
							|SLAVE_SELECT4_Pin|SLAVE_SELECT5_Pin|SLAVE_SELECT6_Pin, GPIO_PIN_SET);

	/*Configure GPIO pins : LIN_IRQ4_Pin LIN_IRQ3_Pin */
	GPIO_InitStruct.Pin = LIN_IRQ4_Pin|LIN_IRQ3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : LIN_IRQ2_Pin LIN_IRQ1_Pin */
	GPIO_InitStruct.Pin = LIN_IRQ2_Pin|LIN_IRQ1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins :  SLAVE_SELECT1_Pin SLAVE_SELECT2_Pin SLAVE_SELECT3_Pin
							 SLAVE_SELECT4_Pin SLAVE_SELECT5_Pin SLAVE_SELECT6_Pin */
	GPIO_InitStruct.Pin = SLAVE_SELECT1_Pin|SLAVE_SELECT2_Pin|SLAVE_SELECT3_Pin
							|SLAVE_SELECT4_Pin|SLAVE_SELECT5_Pin|SLAVE_SELECT6_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : LIN_ENABLE12_Pin LIN_ENABLE34_Pin LIN_ENABLE56_Pin */
	GPIO_InitStruct.Pin = LIN_ENABLE12_Pin|LIN_ENABLE34_Pin|LIN_ENABLE56_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);


}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void enable_gen2_interrupts(void)
{
	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void disable_gen2_interrupts(void)
{
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	HAL_NVIC_DisableIRQ(EXTI1_IRQn);
	HAL_NVIC_DisableIRQ(EXTI4_IRQn);
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void SPI2_Init(void)
{

  /* SPI2 parameter configuration*/
  spi2.Instance = SPI2;
  spi2.Init.Mode = SPI_MODE_MASTER;
  spi2.Init.Direction = SPI_DIRECTION_2LINES;
  spi2.Init.DataSize = SPI_DATASIZE_8BIT;
  spi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  spi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  spi2.Init.NSS = SPI_NSS_SOFT;
  spi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  spi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  spi2.Init.TIMode = SPI_TIMODE_DISABLE;
  spi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  spi2.Init.CRCPolynomial = 15;
  if (HAL_SPI_Init(&spi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* ----------------------------------------------------------------------------*/

