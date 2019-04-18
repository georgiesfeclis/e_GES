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
#include <uart_buffer.h>

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

//	__DSB();

	uart_data_transfer_status_set(INCOMPLETE);
}
/* ---------------------------------------------------------------------------*/