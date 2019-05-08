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
#include <header.h>
#include "uart_buffer.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
static t_Header_PacketID UART_PackID = NO_DATA;
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
/* ----------------------------------------------------------------------------*/
void header_uart_packID_set(const uint8_t packetBuffer[])
{
	if((packetBuffer[HEADER_BYTE_INDEX] & HEADER_PACK_ID_MASK) == SENSOR_DATA_FLAG)
	{
		UART_PackID = SENSOR_DATA;
	}
	else if((packetBuffer[HEADER_BYTE_INDEX] & HEADER_PACK_ID_MASK) == CONFIG_DATA_FLAG)
	{
		UART_PackID = CONFIG_DATA;
	}
}
/* ----------------------------------------------------------------------------*/


/* ----------------------------------------------------------------------------*/
t_Header_PacketID header_uart_packID_get(void)
{
	return UART_PackID;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint8_t get_data_size(const uint8_t packetBuffer[])
{
	return packetBuffer[SIZE_BYTE_INDEX];
}
/* ----------------------------------------------------------------------------*/
