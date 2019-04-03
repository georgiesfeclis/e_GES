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
#include "stdint.h"
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
/*
 * This function returns the type of data that has been sent from PC
 * based on parsed in pointed rx buffer
 */
t_Header_PacketID read_datapack_type_header(uint8_t *pBuffer)
{
	t_Header_PacketID retVal = ERROR_DATA;

	if((pBuffer[0] & HEADER_PACK_ID_MASK) == SENSOR_DATA_FLAG)
	{
		retVal = SENSOR_DATA;
	}
	else if((pBuffer[0] & HEADER_PACK_ID_MASK) == CONFIG_DATA_FLAG)
	{
		retVal = CONFIG_DATA;
	}

	return retVal;
}

/*
 * Empty buffer
 */
void clear_buffer(uint8_t * pBuffer)
{
	uint8_t i = 0;

	for(i = 0; i < sizeof(pBuffer); i++)
	{
		pBuffer[i] = 0;
	}
}



