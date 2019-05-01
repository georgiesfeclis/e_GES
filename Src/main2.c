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
#include "uart_buffer.h"
#include "init.h"
#include "path.h"
#include "header.h"
#include "G5Datagrams.h"
#include "uart_isr.h"
#include "common.h"
#include "process_packet.h"
#include "spi_slave.h"
#include "Gen5_init.h"
#include "Gen2_init.h"

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

int main(void)
{
	uint8_t * const packetBuffer = uart_rxBuffer_get();
	uint8_t message[4] = {0xA5, 0x5A, 0x45, 0x2D};
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	//	  MX_SPI1_Init();
	MX_USART1_UART_Init();
	//	  MX_DAC_Init();
	//	  MX_SPI2_Init();

	path_init();
	gen2_GPIOs_init();

	SPI1_Init();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	uart_isr_init();
//	HAL_SPI_Transmit(&spi1, &message[0], 4, HAL_MAX_DELAY);


	/* Infinite loop */
	while (1)
	{

	  if(uart_data_transfer_status_get() == COMPLETE)
	  {
		  process_packet(&packetBuffer[0]);
		  packetBuffer_reset();
	  }
	  counter();
	  HAL_SPI_Transmit(&spi1, &message[0], 4, HAL_MAX_DELAY);

	  HAL_Delay(500);

  }

}

/* ---------------------------------------------------------------------------*/
