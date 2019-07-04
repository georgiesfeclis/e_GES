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
	gen2_GPIOs_init();
	//activate spi
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void gen2_periph_deinit(void)
{
	gen2_GPIOs_init();
	//deactivate spi
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
/* SPI2 init function */
void Configure_SPI2(void)
{

  LL_SPI_InitTypeDef SPI_InitStruct;

  LL_GPIO_InitTypeDef GPIO_InitStruct;

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

  /**SPI2 GPIO Configuration
  PB13   ------> SPI2_SCK
  PB14   ------> SPI2_MISO
  PB15   ------> SPI2_MOSI
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_13|LL_GPIO_PIN_14|LL_GPIO_PIN_15;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* SPI2 interrupt Init */
  NVIC_SetPriority(SPI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(SPI2_IRQn);

  /* SPI2 parameter configuration*/
  SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
  SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
  SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
  SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
  SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
  SPI_InitStruct.NSS = LL_SPI_NSS_SOFT;
  SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
  SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
  SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
  SPI_InitStruct.CRCPoly = 15;
  LL_SPI_Init(SPI2, &SPI_InitStruct);

  LL_SPI_SetStandard(SPI2, LL_SPI_PROTOCOL_MOTOROLA);

  /* Enable SPI TX, RX and ERROR interrupt registers. */
  SPI2->CR2 |= SPI_CR2_RXNEIE;
  SPI2->CR2 |= SPI_CR2_TXEIE;
  SPI2->CR2 |= SPI_CR2_ERRIE;

}
/* ----------------------------------------------------------------------------*/

