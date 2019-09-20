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
#include "Gen5/Gen5_comms.h"
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
uint8_t txByteIndex = 1;
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

	Configure_RF_Events();

//	path_init();

//	uart_isr_init();
//	ring_buffer_clear();
	SPI1_Tx_Callback();
	txByteIndex = 1;


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
			Reset_SpiTx_Flag();

			/* Tx Byte index is set to 1 because the first byte in each transmission is pre-loaded */
			txByteIndex = 1;
			/* Pre-load the Data Register with data for next transmission. it will always be the system event byte */
			SPI1->DR = RfEvent0.system_ev_byte;

			SpiTxStates = SpiEventTxState;
		}


//		CurrentState = Return_Current_State();

//		if((set == CurrentState) && (reset == PreviousState))
//		{
//			Reset_TxFlag();
//			index = 1;
//			SpiTxStates = SpiEventTxState;
//			Reset_RxCount();
//			reset_count++;
//		}
//		else if((set == CurrentState) && (set == PreviousState))
//		{
//			SPI1->DR = RfEvents.RfEvent0.system_ev_byte;
//		}

//		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) == GPIO_PIN_SET)
//		{
//			Reset_SpiTx_Flag();
//			stateIndex = 0;
////			SpiTxStates = SpiEventTxState;
////			SPI1->DR = RfEvents.RfEvent0.system_ev_byte;
////			while (!(SPI1->SR & (SPI_SR_TXE)));
//			Reset_RxCount();
////			reset_count++;
//		}

		else if(Get_SpiTx_Flag())
		{

			switch(SpiTxStates)
			{
			/* First 2 bytes of each data transmission are event bytes */
			case SpiEventTxState:

//				/* Unless the command requires all event bytes, move on to transmitting sensor data after tx'ing the first 2 events */
//				if ((Get_RfCommand_Name() != RF_CMD_GET_EV_BYTES) && (txByteIndex > 1))
//				{
//					SpiTxStates = SpiHandlingState;
//				}

				switch(txByteIndex)
				{
				/* start from 1 as 0 is the first event byte sent and it is pre-loaded into the data register */
				case 1:
					SPI1->DR = RfEvent1.event_ev_byte;
					SpiTxStates = WaitForTransfer1;
				break;
				case 2:
					SPI1->DR = RfEvent2.power_ev_byte;
					SpiTxStates = WaitForTransfer1;
				break;
				case 3:
					SPI1->DR = RfEvent3.config_ev_byte;
					SpiTxStates = WaitForTransfer1;
				break;

				default:
					/* TODO: some sort of error handling here */
//					SPI1->DR = 0x00;
//					SpiTxStates = WaitForTransfer;
				break;
				} /* close small switch */

			break; /* break from first state in big switch */

			/* Make sure data has been moved to shift register before overwriting the tx data register */
			case WaitForTransfer1:
				/* Wait for transfer complete flag */
				if((SPI1->SR & (SPI_SR_TXE)))
				{
					SpiTxStates = SpiEventTxState;
					txByteIndex++;
				}
				/* Unless the command requires all event bytes, move on to transmitting sensor data after tx'ing the first 2 events */
				else if ((Get_RfCommand_Name() != RF_CMD_GET_EV_BYTES) && (txByteIndex > 1))
				{
					SpiTxStates = SpiHandlingState;
				}
			break;

			/* Handle command received from ECU and Tx sensor data*/
			case SpiHandlingState:

				switch(Get_RfCommand_Name())
				{
				case RF_CMD_READ_RX_FILL:
					SPI1->DR = 0x10;
				break;
				case RF_CMD_READ_RSSI_FILL:
					SPI1->DR = 0x03;
				break;

				case 0x13:
				break;
//				case RF_CMD_READ_RSSI_FIFO:
				default:
					/* TODO: add some sort of error handling */
				break;
				} /* end of command handling switch */
			break;

			/* Make sure data has been moved to shift register before overwriting the tx data register */
			case WaitForTransfer2:
				while(!(SPI1->SR & (SPI_SR_TXE)))
			break;

		break;
			} /* end of big switch */

		} /* enf of if statement */

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
