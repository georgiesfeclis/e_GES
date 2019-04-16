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
#include "process_packet.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "common.h"
#include "header.h"
#include "path.h"

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
/* ----------------------------------------------------------------------------*/
/*
 *
 */

uint8_t process_packet(const uint8_t packetBuffer[])
{
	uint8_t retVal;

	header_uart_packID_set(packetBuffer);

	switch(header_uart_packID_get())
	{
	case CONFIG_DATA:
		init_path_for_header_config(packetBuffer);
		retVal = OK;
	break;

	case SENSOR_DATA:
		transmit_data_via_path(packetBuffer);
		retVal = OK;
	break;

	default:
		retVal = NOK;
	break;
	}

	return retVal;
}


