/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */


/* ----------------------------------------------------------------------------
 * Implements
 */
#include <Gen5/Gen5_comms.h>
/* ----------------------------------------------------------------------------
 * Uses
 */
#include <Gen5/rf_commands.h>
/* ----------------------------------------------------------------------------
 * Private types
 */

static t_system_ev system_ev;
static t_event_ev event_ev;
static t_power_ev power_ev;
static t_config_ev config_ev;
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
void rf_event_clear_all(void)
{
	system_ev.system_ev_byte = 0;
	event_ev.event_ev_byte   = 0;
	power_ev.power_ev_byte   = 0;
	config_ev.config_ev_byte = 0;
}
/* ----------------------------------------------------------------------------*/
uint8_t rf_event_sys_get(void)
{
	return system_ev.system_ev_byte;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint8_t rf_event_event_get(void)
{
	return event_ev.event_ev_byte;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint8_t rf_event_power_get(void)
{
	return power_ev.power_ev_byte;
}
/* ----------------------------------------------------------------------------*/

///* ----------------------------------------------------------------------------*/
uint8_t rf_event_config_get(void)
{
	return config_ev.config_ev_byte;
}
///* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void rf_reset_cmd_handle(void)
{
	system_ev.sys_ev_bits.sys_rdy = 1;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint8_t rf_cmd_handle(const uint8_t spiRxByte)
{
	uint8_t retVal;
	switch(spiRxByte)
	{
	case RF_CMD_READ_RX_FILL:
			system_ev.sys_ev_bits.sys_rdy = BIT_SET;
			retVal = system_ev.system_ev_byte;
		break;
	case RF_CMD_GET_EV_BYTES:
			system_ev.sys_ev_bits.sys_rdy = BIT_SET;
			retVal = system_ev.system_ev_byte;
			break;
	case 0x00:
		retVal = event_ev.event_ev_byte;
		break;
	default:
		retVal = 0x00;
		break;
	}

	return retVal;
}
/* ----------------------------------------------------------------------------*/
