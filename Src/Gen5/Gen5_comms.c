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
#include <Gen5/gen5_comms.h>
#include <Gen5/rf_commands.h>
/* ----------------------------------------------------------------------------
 * Private types
 */

static t_system_ev system_ev;
static t_event_ev event_ev;
static t_power_ev power_ev;
static t_config_ev config_ev;

static uint16_t rxCount = 0;
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
void Increment_RxCount(void)
{
	rxCount++;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint16_t Get_RxCount(void)
{
	return rxCount;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void Reset_RxCount(void)
{
	rxCount = 0;
}
/* ----------------------------------------------------------------------------*/
void Configure_RF_Events(void)
{
	system_ev.system_ev_byte = 0x04;
	event_ev.event_ev_byte   = 0x07;
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

/* ----------------------------------------------------------------------------*/
uint8_t rf_event_config_get(void)
{
	return config_ev.config_ev_byte;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void rf_reset_cmd_handle(void)
{
	system_ev.sys_ev_bits.sys_rdy = 1;
}
/* ----------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
uint8_t get_conifgured_cfg_byte(void)
{
	config_ev.config_ev_bits.pathB = 1;
	config_ev.config_ev_bits.ser = 3;

	return config_ev.config_ev_byte;
}

