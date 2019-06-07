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
#include <Gen5/Gen5_init.h>
#include "common.h"
//#include "init.h"
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

/* ---------------------------------------------------------------------------*/
void gen5_periph_init(void)
{
	SPI1_Init();
	G5_IRQ_Pin_Init();
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void gen5_periph_deinit(void)
{
	GPIOC -> ODR &= G5_IRQ_Pin;
	//TODO Error Handler?
	HAL_SPI_DeInit(&spi1);
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  spi1.Instance = SPI1;
  spi1.Init.Mode = SPI_MODE_SLAVE;
  spi1.Init.Direction = SPI_DIRECTION_2LINES;
  spi1.Init.DataSize = SPI_DATASIZE_8BIT;
  spi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  spi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  spi1.Init.NSS = SPI_NSS_SOFT;
  spi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  spi1.Init.TIMode = SPI_TIMODE_DISABLE;
  spi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  spi1.Init.CRCPolynomial = 15;
  if (HAL_SPI_Init(&spi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void G5_IRQ_Pin_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	/*Configure GPIO pin Output Level */
	GPIOC -> ODR &= G5_IRQ_Pin;

	/*Configure GPIO pin : G5_IRQ_Pin */
	GPIO_InitStruct.Pin = G5_IRQ_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(G5_IRQ_GPIO_Port, &GPIO_InitStruct);
}
/* ---------------------------------------------------------------------------*/
