/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */


/* ----------------------------------------------------------------------------
 * Implements
 */
#include "main.h"
/* ----------------------------------------------------------------------------
 * Uses
 */

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
static volatile uint8_t spi1RxBuffer[700];
static volatile uint32_t spi1ReceiveIndex = 0;
/* ----------------------------------------------------------------------------
 * Private functions
 */

/* ----------------------------------------------------------------------------
 * Public variables
 */

/* ----------------------------------------------------------------------------
 * Public functions
 */
void Activate_SPI1(void)
{
  /* Enable SPI1 */
  SPI1->CR1 |= SPI_CR1_SPE;
}

/*
 * SPI Receive Callback
 */
void SPI1_Rx_Callback(void)
{
  /* Read character in Data register.
  RXNE flag is cleared by reading data in DR register */
  spi1RxBuffer[spi1ReceiveIndex++] = SPI1->DR;
}

/*
 * SPI Transfer Error Callback
 */
void SPI1_TransferError_Callback(void)
{
  /* Disable RXNE  Interrupt             */
  SPI1->CR2 &= SPI_CR2_RXNEIE;

  /* Disable TXE   Interrupt             */
  SPI1->CR2 &= SPI_CR2_TXEIE;

/* TODO: blink error LED*/
}

/* SPI1 init function */
void Configure_SPI1(void)
{

  LL_SPI_InitTypeDef SPI_InitStruct;

  LL_GPIO_InitTypeDef GPIO_InitStruct;

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

  /**SPI1 GPIO Configuration
  PA4   ------> SPI1_NSS
  PA6   ------> SPI1_MISO
  PA7   ------> SPI1_MOSI
  PB3   ------> SPI1_SCK
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_4|LL_GPIO_PIN_6|LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* SPI1 interrupt Init */
  NVIC_SetPriority(SPI1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(SPI1_IRQn);

  /* SPI1 parameter configuration*/
  SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
  SPI_InitStruct.Mode = LL_SPI_MODE_SLAVE;
  SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
  SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
  SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
  SPI_InitStruct.NSS = LL_SPI_NSS_HARD_INPUT;
  SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
  SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
  SPI_InitStruct.CRCPoly = 15;
  LL_SPI_Init(SPI1, &SPI_InitStruct);

  LL_SPI_SetStandard(SPI1, LL_SPI_PROTOCOL_MOTOROLA);

  /* Enable SPI TX, RX and ERROR interrupt registers. */
  SPI1->CR2 |= SPI_CR2_RXNEIE;
  SPI1->CR2 |= SPI_CR2_TXEIE;
  SPI1->CR2 |= SPI_CR2_ERRIE;

}
