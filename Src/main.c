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

//static uint8_t TxData[] = "some stuff going on in background\n";
//uint8_t SPI_Rx[10] = {0};
/* ----------------------------------------------------------------------------
 * Public functions
 */

int main(void)
{
	uint8_t * const packetBuffer = uart_rxBuffer_get();

	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	//	  MX_SPI1_Init();
	MX_USART1_UART_Init();
	//	  MX_DAC_Init();
	//	  MX_SPI2_Init();


	path_init();

	uart_isr_init();


	/* Infinite loop */
	while (1)
	{

	//	  HAL_SPI_Receive(&spi1, &SPI_Rx[0], 10, HAL_MAX_DELAY);
	//	  HAL_UART_Transmit(&uart1, &TxData[0], 35, HAL_MAX_DELAY);
	//	  HAL_Delay(500);

	  if(uart_data_transfer_status_get() == COMPLETE)
	  {
		  process_packet(&packetBuffer[0]);
		  PacketBuffer_Reset();
	  }

  }

}
