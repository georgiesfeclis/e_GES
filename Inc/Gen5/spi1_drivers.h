/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_SPI1_DRIVERS_H_
#define GEN5_SPI1_DRIVERS_H_

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

/* ---------------------------------------------------------------------------
 * Types
 */
typedef enum
{
	SysEventState = 0,
	EvEventState = 1,
	HandlingState = 2
//	DataTxState = 3,
//	ErrorState = 0xFF
} t_states;

typedef enum
{
	BufEmpty = 0,
	BufNotEmpty = 1
} t_BufStatus;
/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
void Activate_SPI1(void);
void SPI1_Rx_Callback(void);
void SPI1_Tx_Callback(void);
void SPI1_TransferError_Callback(void);
void Configure_SPI1(void);
void G5_IRQ_Pin_Init(void);
uint8_t get_tx_flag(void);
void set_tx_flag(void);
void reset_tx_flag(void);
void Activate_IRQ_on_chip_select(void);

#endif /* GEN5_SPI1_DRIVERS_H_ */
