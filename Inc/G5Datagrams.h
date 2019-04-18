/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi-line overview here if useful.
 */


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
#define ROTATION_DATA_PACK_ID        ((uint8_t) 0xE7)
#define STATUS_LEARN_DATA_PACK_ID    ((uint8_t) 0xA3)
#define STATUS_DATA_PACK_ID          ((uint8_t) 0x83)
#define AK_DATA_PACK_ID              ((uint8_t) 0x00)

/* ---------------------------------------------------------------------------
 * Types
 */


/*
 * This structure replicates the Gen 5 Rotation Telegram structure
 * This is only transmitted in learning mode
 */
typedef struct
{
	uint8_t    Sync1;
	uint8_t    Sync2;
	uint8_t    PacketID;
	uint32_t   SensorID;
	uint16_t   RotationData;
	uint8_t    CheckSum;
} t_G5RotationDatagram;

t_G5RotationDatagram G5RotationDatagram;
/*
 * This Structure replicates the Gen 5 Status Telegram structure
 * This can be transmitted both in learning mode (if Packet ID = A3)
 * or in the other modes (Normal Driving, Delta P) - (if Packet ID = 83)
 */
typedef struct
{
	uint8_t    Sync1;
	uint8_t    Sync2;
	uint8_t    PacketID;
	uint32_t   SensorID;
	uint8_t    StatusField1;
	uint8_t    StatusField2;
	uint8_t    SensorPressure;
	uint8_t    SensorTemperature;
	uint8_t    CheckSum;
} t_G5StatusDatagram;

t_G5StatusDatagram G5StatusDatagram;

/*
 * This structure replicates the Gen 5 AK Telegram structure
 * This is only transmitted in Normal Driving mode
 */
typedef struct
{
	uint8_t    Sync1;
	uint8_t    Sync2;
	uint8_t    PacketID;
	uint32_t   SensorID;
	uint8_t    SensorPressure;
	uint8_t    SensorTemperature;
	uint8_t    CheckSum;
} t_G5AKDatagram;

t_G5AKDatagram G5AKDatagram;

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Read G5 Sensor Packet ID (byte 3) to determine datagram type
 * and assign data to specific structure
 */
uint8_t assign_g5_data_to_datagram(const uint8_t pBuffer[]);
/* ---------------------------------------------------------------------------*/

