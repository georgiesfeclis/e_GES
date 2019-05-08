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
#include "uart_buffer.h"

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
static uint8_t UART_RxBuffer[UART_RX_BUFFER_SIZE];
static uint8_t UART_RxIndex = 0;


static t_uartTransferStatus transferStatus = INCOMPLETE;
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
void uart_rxBuffer_init(void)
{
	uint8_t i;
	for(i = 0; i < sizeof(UART_RxBuffer); i++)
	{
		UART_RxBuffer[i] = 0;
	}
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
uint8_t * uart_rxBuffer_get(void)
{
	return (uint8_t *) &UART_RxBuffer;
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void uart_rxBuffer_update(uint8_t data)
{
	UART_RxBuffer[UART_RxIndex++] = data;
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void uart_rxBuffer_index_reset(void)
{
	UART_RxIndex = 0;
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void uart_data_transfer_status_set(t_uartTransferStatus status)
{
	transferStatus = status;
}
/* ---------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
t_uartTransferStatus uart_data_transfer_status_get(void)
{
	return transferStatus;
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void packetBuffer_reset(void)
{
	uart_rxBuffer_init();
	uart_rxBuffer_index_reset();

	/*TODO: investigate _DSB function - get it to work*/
//	__DSB();

	uart_data_transfer_status_set(INCOMPLETE);
}
/* ---------------------------------------------------------------------------*/
uint8_t process_rx_data(const uint8_t data)
{
	static t_rxType statusType = IDLE_STATE;
	uint8_t retVal = 0;
	static uint8_t sizeByte = 0;
	static uint8_t i = 0;
	uint8_t calculated_crc = 0;

	switch(statusType)
	{
	case IDLE_STATE:
		sizeByte = data;
		statusType = RXDATA_STATE;
		break;

	case RXDATA_STATE:
		if(i < sizeByte)
		{
			uart_rxBuffer_update(data);
			i++;
		}
		else if (i == sizeByte)
		{
			calculated_crc = rx_buffer_crc_calculation();

			if(calculated_crc == data)
			{
				statusType = IDLE_STATE;
				retVal = OK;
			}
			else
			{
				statusType = IDLE_STATE;
				retVal = NOK;
			}

			i = 0;
		}
		break;

	default:
		retVal = NOK;
	break;
	}

	return retVal;
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
uint8_t rx_buffer_crc_calculation(void)
{
	uint32_t sum = 0;
	uint8_t masked_sum = 0;
	uint8_t CRC = 0;
	uint8_t i;
	for(i=0; i < sizeof(UART_RxBuffer); i++)
	{
		sum += (uint32_t)UART_RxBuffer[i];
	}
	masked_sum = (uint8_t)(sum & BYTE_MASK);
	CRC = ~masked_sum;

	return CRC;
}
/* ---------------------------------------------------------------------------*/

