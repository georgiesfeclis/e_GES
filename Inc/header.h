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

t_Header_PacketID read_datapack_type_header(uint8_t *pBuffer);
void clear_buffer(uint8_t * pBuffer);

#endif /* HEADER_H_ */
