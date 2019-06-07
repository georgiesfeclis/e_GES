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
#include <Gen5\spi2_isr.h>
/* ----------------------------------------------------------------------------
 * Uses
 */
//#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal.h"
#include "Gen5\Gen5_init.h"
#include <Gen5\Gen5_comms.h>
#include "Gen5\rf_commands.h"
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
static uint8_t spiRxByte;
//static uint8_t spiTxByte[2] = {0xA5, 0x5A};
/* ----------------------------------------------------------------------------
 * Private functions
 */

/* These are upcalls expected by the HAL layer */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
//void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
/* ----------------------------------------------------------------------------
 * Public variables
 */

/* ----------------------------------------------------------------------------
 * Public functions
 */

/* ----------------------------------------------------------------------------*/
void spi1_isr_init(void)
{
	HAL_SPI_Receive_IT(&spi1, &spiRxByte, sizeof(spiRxByte));
}
/* ----------------------------------------------------------------------------*/


/* ----------------------------------------------------------------------------*/
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
//	uint8_t txByte;
//	uint8_t i;
	if (hspi->Instance == SPI1)
	{
////		txByte = rf_cmd_handle(spiRxByte);
////		HAL_SPI_Transmit_IT(&spi1, &txByte, sizeof(txByte));
//
//		for(i=0; i< 2; i++)
//		{
//			HAL_SPI_Transmit_IT(&spi1, spiTxByte, 2);
//		}
//

//			HAL_GPIO_WritePin(G5_IRQ_GPIO_Port, G5_IRQ_Pin, GPIO_PIN_SET);
		uint8_t tx_byte = 0;
		tx_byte = rf_cmd_handle(spiRxByte);
		HAL_SPI_Transmit_IT(&spi1, &tx_byte, sizeof(tx_byte));

	}

	HAL_SPI_Receive_IT(&spi1, &spiRxByte, sizeof(spiRxByte));

}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
//void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
//{
//	if (hspi->Instance == SPI1)
//	{
////		HAL_GPIO_WritePin(G5_IRQ_GPIO_Port, G5_IRQ_Pin, GPIO_PIN_SET);
//	}
//}
/* ----------------------------------------------------------------------------*/
