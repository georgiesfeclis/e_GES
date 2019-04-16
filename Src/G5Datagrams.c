/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author Georgiana-Elena Sfeclis
 *
 * One line summary
 *
 * Multi-line overview here if useful.
 */


/* ----------------------------------------------------------------------------
 * Implements
 */
#include "G5Datagrams.h"

/* ----------------------------------------------------------------------------
 * Uses
 */
#include "init.h"
#include "common.h"
#include "stm32f4xx_hal.h"

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
 * Read G5 Sensor Packet ID (byte 3) to determine datagram type
 * and assign data to specific structure
 */
uint8_t assign_g5_data_to_datagram(const uint8_t pBuffer[])
{
	uint8_t retVal;
	uint8_t gen5_packet_id = pBuffer[3];


	switch(gen5_packet_id)
	{
	case(ROTATION_DATA_PACK_ID):
		G5RotationDatagram.Sync1         = pBuffer[1];
		G5RotationDatagram.Sync2         = pBuffer[2];
		G5RotationDatagram.PacketID      = pBuffer[3];
		G5RotationDatagram.SensorID      = ((uint32_t) pBuffer[4] << 24)
				                          |((uint32_t) pBuffer[5] << 16)
										  |((uint32_t) pBuffer[6] << 8)
										  |((uint32_t) pBuffer[7]);
		G5RotationDatagram.RotationData  = ((uint16_t) pBuffer[8] << 8) | ((uint16_t) pBuffer[9]);
		G5RotationDatagram.CheckSum      = pBuffer[10];

		retVal = OK;
	break;

	case(STATUS_LEARN_DATA_PACK_ID):
			// intentional fall through
	case(STATUS_DATA_PACK_ID):
		G5StatusDatagram.Sync1              = pBuffer[1];
		G5StatusDatagram.Sync2              = pBuffer[2];
		G5StatusDatagram.PacketID           = pBuffer[3];
		G5StatusDatagram.SensorID           = ((uint32_t) pBuffer[4] << 24)
											 |((uint32_t) pBuffer[5] << 16)
											 |((uint32_t) pBuffer[6] << 8)
											 |((uint32_t) pBuffer[7]);
		G5StatusDatagram.StatusField1       = pBuffer[8];
	    G5StatusDatagram.StatusField2       = pBuffer[9];
	    G5StatusDatagram.SensorPressure     = pBuffer[10];
	    G5StatusDatagram.SensorTemperature  = pBuffer[11];
		G5StatusDatagram.CheckSum           = pBuffer[12];

		retVal = OK;
	break;

	case(AK_DATA_PACK_ID):
		G5AKDatagram.Sync1              = pBuffer[1];
		G5AKDatagram.Sync2              = pBuffer[2];
		G5AKDatagram.PacketID           = pBuffer[3];
		G5AKDatagram.SensorID           = ((uint32_t) pBuffer[4] << 24)
										 |((uint32_t) pBuffer[5] << 16)
										 |((uint32_t) pBuffer[6] << 8)
										 |((uint32_t) pBuffer[7]);

		G5AKDatagram.SensorPressure     = pBuffer[8];
		G5AKDatagram.SensorTemperature  = pBuffer[9];
		G5AKDatagram.CheckSum           = pBuffer[10];

		retVal = OK;
	break;

	default:
		retVal = NOK;
	break;
	}

	return retVal;

}



/*******************************************************************************************************************************/


/*******************************************************************************************************************************/
