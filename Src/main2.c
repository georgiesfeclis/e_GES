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
#include "Gen5/gen5_comms.h"
#include "Gen5/rf_commands.h"
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
uint32_t tick_reset;
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


	/* Infinite loop */
	while (1)
	{
		/* Fill in Sensor Data circular buffer with data from PC */
//	  if(uart_data_transfer_status_get() == COMPLETE)
//	  {
//		  ring_buffer_queue(packetBuffer);
//		  packetBuffer_reset();
//	  }

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == 1)
		{

			Reset_RxCount();
			tick_reset = HAL_GetTick();
		}




//		switch(Get_RfCommand_Name())
//		{
//		case RF_CMD_SET_WDG:
//		case RF_CMD_SYS_RESET:
//			if(Get_RxCount() == 2)
//			{
//				Reset_RxCount();
//			}
//			break;
//		case RF_CMD_READ_RX_FILL:
//		case RF_CMD_READ_RSSI_FILL:
//		case RF_CMD_SET_SYS_MODE:
//			if(Get_RxCount() == 2)
//			{
//				Reset_RxCount();
//			}
//			break;
//		case RF_CMD_GET_EV_BYTES:
//			if(Get_RxCount() == 4)
//			{
//				Reset_RxCount();
//			}
//			break;
//		default:
//			if (Get_RfCommand_Size() == (Get_RxCount()-1))
//			{
//				Reset_RxCount();
//			}
//			break;
//		}
	}

}

/* ---------------------------------------------------------------------------*/
