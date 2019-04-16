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

/* ----------------------------------------------------------------------------
 * Uses
 */
#include <string.h>
#include "common.h"
#include "init.h"
#include "G5Datagrams.h"
#include "uart_buffer.h"
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
static uint8_t current_path;
/* ----------------------------------------------------------------------------
 * Private functions
 */

/* ----------------------------------------------------------------------------
 * Public variables
 */

uint8_t ErrorMessage[] = "Wrong path!";
/* ----------------------------------------------------------------------------
 * Public functions
 */


/* ---------------------------------------------------------------------------*/
/*
 * Used to set default path as No data path
 */
void path_init(void)
{
	current_path = NO_DATA_PATH_FLAG;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * This function reads the sensor type from the header and sends the command to
 * initialise path for specific header
 */
uint8_t init_path_for_header_config(const uint8_t pBuffer[])
{
	uint8_t retVal = NOK;
	uint8_t pathType = pBuffer[0] & HEADER_PATH_MASK;

	if(NO_DATA_PATH_FLAG == current_path)
	{
		/* there is not currently a path assigned so set one up */
		retVal = set_path(pathType);
	}
	else if(get_path() != pathType){
		/*
		 * there is currently a path assigned.
		 * if this is different to the requested path, de-init it
		 * and init the desired path
		 */
		clear_path(pathType);

		retVal = set_path(pathType);
	}

	return retVal;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * Check data from buffer matches the current
 * initialised path and send command to transmit data
 */
uint8_t transmit_data_via_path(const uint8_t pBuffer[])
{
	uint8_t retVal = NOK;
	uint8_t pathType = pBuffer[0] & HEADER_PATH_MASK;

	if(get_path() == pathType)
	{
		/* the path matches the header data, now assign it to the right sensor and transmit */
		retVal = transmit_sensor_data(pathType, pBuffer);
	}
//	else
//	{
//		HAL_UART_Transmit_IT(&uart1, &ErrorMessage[0], strlen(&ErrorMessage[0]));
//	}

	return retVal;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * Actual initialisation of a path depending
 * on the path type passed in
 */
uint8_t set_path(uint8_t pathType)
{

	uint8_t retVal;

	switch(pathType)
	{

	case (GEN5_PATH_FLAG):
		MX_SPI1_Init();
		retVal = OK;
	break;

	default:
		retVal = NOK;
	break;
	}

	current_path = pathType;

	return retVal;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * Transmit data using right path
 */
uint8_t transmit_sensor_data(uint8_t pathType, const uint8_t pBuffer[])
{
	uint8_t retVal = NOK;

	switch(pathType)
	{
	case(GEN5_PATH_FLAG):
			/*
			 * G5 ECU will request the specific data stored in the datagrams
			 * once it receives the an interrupt saying that the buffer is full
			 */
		retVal = assign_g5_data_to_datagram(pBuffer);
	break;

	default:
		retVal = NOK;
	break;
	}

	return retVal;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * Read current path initialised
 */
uint8_t get_path(void)
{
	return current_path;
}
/* ---------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------*/
/*
 * De-init path passed in
 */
void clear_path(uint8_t pathType)
{
	switch(pathType)
	{
	case(GEN5_PATH_FLAG):
		HAL_SPI_DeInit(&spi1);
	break;
	}
}
/* ---------------------------------------------------------------------------*/
