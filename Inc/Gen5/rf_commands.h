/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_RF_COMMANDS_H_
#define GEN5_RF_COMMANDS_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include <stdint.h>
/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */

#define RF_CMD_READ_RX_FILL          ((uint8_t) 0x01)
#define RF_CMD_READ_RSSI_FILL        ((uint8_t) 0x03)
#define RF_CMD_GET_EV_BYTES          ((uint8_t) 0x04)
#define RF_CMD_READ_RSSI_FIFO        ((uint8_t) 0x05)
#define RF_CMD_READ_RX_FIFO          ((uint8_t) 0x06)
#define RF_CMD_WRITE_SRAM            ((uint8_t) 0x07)
#define RF_CMD_SET_SYS_MODE          ((uint8_t) 0x0D)
#define RF_CMD_SET_WDG               ((uint8_t) 0x10)
#define RF_CMD_SYS_RESET             ((uint8_t) 0x15)

#define RF_CMD_DUMMY                 ((uint8_t) 0x00)
/* ---------------------------------------------------------------------------
 * Types
 */

/* NOTE1: Bit field structures below may not be portable to other compilers */

/* NOTE2: All the bit names reflect the register names for event bytes
 * For further details please check datasheet of Atmel ATA5785
 */

/* ---------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		uint8_t reserved0 : 1;
		uint8_t DFifo     : 1;
		uint8_t reserved1 : 1;
		uint8_t SFifo     : 1;
		uint8_t avcclow   : 1;
		uint8_t sys_rdy   : 1;
		uint8_t cmd_rdy   : 1;
		uint8_t sys_err   : 1;
	} sys_ev_bits;

	uint8_t system_ev_byte;

} t_system_ev;
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		uint8_t eotb   : 1;
		uint8_t sotb   : 1;
		uint8_t wcokb  : 1;
		uint8_t idchkb : 1;
		uint8_t eota   : 1;
		uint8_t sota   : 1;
		uint8_t wcoka  : 1;
		uint8_t idchka : 1;
	} event_ev_bits;

	uint8_t event_ev_byte;

} t_event_ev;
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		uint8_t npwron1  : 1;
		uint8_t npwron2  : 1;
		uint8_t npwron3  : 1;
		uint8_t npwron4  : 1;
		uint8_t npwron5  : 1;
		uint8_t npwron6  : 1;
		uint8_t reserved : 1;
		uint8_t pwron    : 1;
	} power_ev_bits;

	uint8_t power_ev_byte;

} t_power_ev;
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		uint8_t ser      : 3;
		uint8_t reserved : 1;
		uint8_t ch       : 2;
		uint8_t pathA    : 1;
		uint8_t pathB    : 1;
	} config_ev_bits;

	uint8_t config_ev_byte;

} t_config_ev;
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

#endif /* GEN5_RF_COMMANDS_H_ */
