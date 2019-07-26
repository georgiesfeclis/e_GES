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
#include "Gen5/spi1_drivers.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "main.h"
#include "Gen5/gen5_comms.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
//static t_states txState;
/* ----------------------------------------------------------------------------
 * Private defines
 */

/* ----------------------------------------------------------------------------
 * Private macros
 */

/* ----------------------------------------------------------------------------
 * Private variables 
 */
static uint8_t spi1RxBuffer[5];
static uint32_t spi1DataIndex = 0;
uint8_t dataToSend = 0xCB;
static t_BufStatus TxFlag = BufEmpty;
volatile t_states txState = SysEventState;
/* ----------------------------------------------------------------------------
 * Private functions
 */

/* ----------------------------------------------------------------------------
 * Public variables
 */

/* ----------------------------------------------------------------------------
 * Public functions
 */
t_BufStatus get_tx_flag(void)
{
	return TxFlag;
}

void set_tx_flag(void)
{
	TxFlag = BufNotEmpty;
}

void reset_tx_flag(void)
{
	TxFlag = BufEmpty;
}

/*
 * SPI1 Activation - enable register
 */
/* ---------------------------------------------------------------------------*/
void Activate_SPI1(void)
{
  /* Enable SPI1 */
  SPI1->CR1 |= SPI_CR1_SPE;
}
/* ---------------------------------------------------------------------------*/
/*
 * Check for chip select
 */
void Activate_IRQ_on_chip_select(void)
{
	if(LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_4))
	{
		  /* Disable SPI TX, RX and ERROR interrupt registers. */
		  SPI1->CR2 &= SPI_CR2_RXNEIE;
		  SPI1->CR2 &= SPI_CR2_TXEIE;
		  txState = SysEventState;
//		  SPI1->CR2 |= SPI_CR2_ERRIE;
	}
	else
	{
		/* Enable SPI TX, RX and ERROR interrupt registers. */

		SPI1->CR2 |= SPI_CR2_RXNEIE;
		SPI1->CR2 |= SPI_CR2_TXEIE;


//		  SPI1->CR2 &= SPI_CR2_ERRIE;
	}
}

/*
 * Reset SPI data index
 */
void Reset_SPI1_data_index(void)
{
	spi1DataIndex = 0;
}
/*
 * SPI1 Receive Callback
 */
/* ---------------------------------------------------------------------------*/
void SPI1_Rx_Callback(void)
{
  /* Read character in Data register.
  RXNE flag is cleared by reading data in DR register */

	spi1RxBuffer[spi1DataIndex++] = SPI1->DR;


}
/* ---------------------------------------------------------------------------*/

/*
 * SPI1 Transmit Callback
 */

/* ---------------------------------------------------------------------------*/
void SPI1_Tx_Callback(void)
{
  /* Write character in Data register.
  TXE flag is cleared by writing data to DR register */
	switch(txState)
	{

	case(SysEventState):
			SPI1->DR = rf_event_sys_get();
			txState = EvEventState;
	break;

	case (EvEventState):
			SPI1->DR = rf_event_event_get();
			txState = HandlingState;
	break;

	case(HandlingState):
			SPI1->DR = 0x00;
////			switch(spi1RxBuffer[0])
////			{
////				//TODO: create state machine for command control? - should be in g5 comms.
////			}
////			txState = DataTxState;
	break;
//
//	case (DataTxState):
////			SPI1->DR = data?
//		break;
//	case(ErrorState):
//			break;
//
	}
}
/* ---------------------------------------------------------------------------*/

/*
 * SPI Transfer Error Callback
 */
/* ---------------------------------------------------------------------------*/
void SPI1_TransferError_Callback(void)
{
  /* Disable RXNE  Interrupt             */
  SPI1->CR2 &= SPI_CR2_RXNEIE;

  /* Disable TXE   Interrupt             */
  SPI1->CR2 &= SPI_CR2_TXEIE;

/* TODO: blink error LED*/
}
/* ---------------------------------------------------------------------------*/

/* SPI1 init function */
/* ---------------------------------------------------------------------------*/
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
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
	  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
	  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
	  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
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





}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void G5_IRQ_Pin_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, G5_IRQ_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin : G5_IRQ_Pin */
	GPIO_InitStruct.Pin = G5_IRQ_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(G5_IRQ_GPIO_Port, &GPIO_InitStruct);
}
/* ---------------------------------------------------------------------------*/
