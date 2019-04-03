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
#include "uart_isr.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "header.h"
#include "init.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
t_Header_PacketID PackID = NO_DATA;


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
uint8_t RxIndex = 0;
uint8_t TransferStatus = 0;
/* ----------------------------------------------------------------------------
 * Public functions
 */

/* ----------------------------------------------------------------------------*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		if(RxIndex == 0)
		{
		clear_buffer(&RxBuffer[0]);
		}

		if(RxData[0] == ASCII_ENTER)
		{
			PackID = read_datapack_type_header(&RxBuffer[0]);
			RxIndex = 0;
			TransferStatus = 1;
		}
		else
		{
			RxBuffer[RxIndex++] = RxData[0];
		}

		HAL_UART_Receive_IT(&uart1, &RxData[0], 1);
	}
}
/* ----------------------------------------------------------------------------*/

