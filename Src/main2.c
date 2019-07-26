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
#include <DataBuffers/ring_buffer.h>
#include <DataBuffers/uart_buffer.h>
#include <DataBuffers/uart_isr.h>
#include "common.h"
#include "init.h"
#include "path.h"
#include "Gen5/spi1_drivers.h"
//#include "header.h"
//#include "G5Datagrams.h"

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
//	t_rxBuffer * const packetBuffer = uart_rxBuffer_get();

	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
//	MX_USART1_UART_Init();

	/* Configure SPI1 Bus, initialise NVIC interrupts and enbale SPI1 interrupt registers, Activate SPI1. */
	Configure_SPI1();
	Activate_SPI1();
	G5_IRQ_Pin_Init();
//	path_init();

//	uart_isr_init();
//	ring_buffer_clear();
//	SPI1_Tx_Callback();
	Activate_IRQ_on_chip_select();
	/* Infinite loop */
	while (1)
	{

//	  if(uart_data_transfer_status_get() == COMPLETE)
//	  {
//		  ring_buffer_queue(packetBuffer);
//		  packetBuffer_reset();
//	  }
	}

}

/* ---------------------------------------------------------------------------*/
