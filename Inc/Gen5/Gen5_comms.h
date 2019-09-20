/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_GEN5_COMMS_H_
#define GEN5_GEN5_COMMS_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include <stdint.h>
#include "Gen5/rf_commands.h"
/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */

#define BIT_SET        1
#define BIT_RESET      0
/* ---------------------------------------------------------------------------
 * Types
 */
typedef struct
{
	uint8_t cmd_name;
	uint8_t cmd_size;
}t_GEN5_RxData;

typedef enum
{
	TxFlagReset = 0,
	TxFlagSet
}t_spiTxFlag;

typedef enum
{
	SpiEventTxState = 0,
	WaitForTransfer1,
	SpiHandlingState,
	WaitForTransfer2
//	SpiDataTxState
}t_SpiTxStates;

t_SpiTxStates SpiTxStates;

t_system_ev RfEvent0;
t_event_ev RfEvent1;
t_power_ev RfEvent2;
t_config_ev RfEvent3;

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
void Increment_RxCount(void);
uint16_t Get_RxCount(void);
void Reset_RxCount(void);

void Set_SpiTx_Flag(void);
void Reset_SpiTx_Flag(void);
t_spiTxFlag Get_SpiTx_Flag(void);

void Update_RfCommand_Name(uint8_t cmd_name);
void Update_RfCommand_Size(uint8_t cmd_size);
uint8_t Get_RfCommand_Name(void);
uint8_t Get_RfCommand_Size(void);
void Configure_RF_Events(void);
void rf_reset_cmd_handle(void);
void rf_event_clear_all(void);
uint8_t rf_event_sys_get(void);
uint8_t rf_event_event_get(void);





#endif /* GEN5_GEN5_COMMS_H_ */
