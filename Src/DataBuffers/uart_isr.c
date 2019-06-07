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
#include <DataBuffers/uart_isr.h>

/* This is an upcall expected by the HAL layer */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* ----------------------------------------------------------------------------
 * Uses
 */
#include <DataBuffers/uart_buffer.h>
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
static uint8_t UART_RxData_Byte = 0;
/* ----------------------------------------------------------------------------
 * Private functions
 */

/* ----------------------------------------------------------------------------
 * Public variables
 */

/* ----------------------------------------------------------------------------
 * Public functions
 */

/* ----------------------------------------------------------------------------*/
void uart_isr_init(void)
{
	HAL_UART_Receive_IT(&uart1, &UART_RxData_Byte, sizeof(UART_RxData_Byte));
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	 // UART interrupt callback - fill in UART RxBuffer

	if (huart->Instance == USART1)
	{
		if (INCOMPLETE == uart_data_transfer_status_get())
		{
			process_rx_data(UART_RxData_Byte);
		}

		HAL_UART_Receive_IT(&uart1, &UART_RxData_Byte, 1);
	}
}
/* ----------------------------------------------------------------------------*/

