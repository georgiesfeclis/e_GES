/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef HEADER_H_
#define HEADER_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include "stdint.h"
/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */

#define HEADER_PACK_ID_MASK      ((uint8_t) 0x03)
#define HEADER_PATH_MASK         ((uint8_t) 0x3C)

#define SENSOR_DATA_FLAG         ((uint8_t) 0x00)
#define CONFIG_DATA_FLAG         ((uint8_t) 0x01)

/* ---------------------------------------------------------------------------
 * Types
 */
typedef enum
{
	SENSOR_DATA = 0,
	CONFIG_DATA,
	NO_DATA,
	ERROR_DATA = 0xFF
}t_Header_PacketID;

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Read UART Rx buffer and set Pack ID type (i.e Sensor data or Configuration data)
 */
void header_uart_packID_set(const uint8_t packetBuffer[]);
/* ----------------------------------------------------------------------------*/

/*
 * Return Pack ID type
 */
t_Header_PacketID header_uart_packID_get(void);
/* ----------------------------------------------------------------------------*/

#endif /* HEADER_H_ */
