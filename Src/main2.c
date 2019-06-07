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
#include <Gen5/Gen5_init.h>
#include "common.h"
#include "init.h"
#include "path.h"
#include "Gen5/rf_commands.h"
#include "Gen5/spi2_isr.h"
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
	t_rxBuffer * const packetBuffer = uart_rxBuffer_get();
//	uint8_t message[4] = {0xA5, 0x5A, 0x45, 0x2D};
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	//	  MX_SPI1_Init();
	MX_USART1_UART_Init();

//	gen3_periph_init();
//	gen2_periph_init();
	gen5_periph_init();
//		  MX_DAC_Init();
//		  MX_SPI2_Init();

	path_init();
//	gen2_GPIOs_init();

//	SPI1_Init();

	uart_isr_init();
	ring_buffer_clear();

//	spi1_isr_init();
//	static uint8_t spiRxByte = 0;
//	HAL_SPI_Receive_IT(&spi1, &spiRxByte, sizeof(spiRxByte));
//	HAL_SPI_Transmit(&spi1, &message[0], 4, HAL_MAX_DELAY);
	  uint8_t val;
	  uint8_t data = 0;
	/* Infinite loop */
	while (1)
	{
// nothing
	  if(uart_data_transfer_status_get() == COMPLETE)
	  {
		  ring_buffer_queue(packetBuffer);
		  packetBuffer_reset();
	  }


//	  val = spiRxByte;
//	  val(&spi1, &val, 1, HAL_MAX_DELAY);

//	  HAL_GPIO_WritePin(G5_IRQ_GPIO_Port, G5_IRQ_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_TogglePin(G5_IRQ_GPIO_Port, G5_IRQ_Pin);
//	  HAL_Delay(300);

//	  system_ev.sys_ev_bits.DFifo = 1;
//	  counter();
	  HAL_SPI_Receive(&spi1, &val, 1, HAL_MAX_DELAY);
	  if(val != 0)
	  {
		  data = val;
	  }
//	  data = val;
//	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
//	  HAL_Delay(500);

  }

}

/* ---------------------------------------------------------------------------*/
