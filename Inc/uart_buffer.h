/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef UART_BUFFER_H_
#define UART_BUFFER_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include "stdint.h"
#include "common.h"

/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */
#define UART_RX_BUFFER_SIZE ((uint8_t) 20)
/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Initialise UART buffer
 */
void uart_rxBuffer_init(void);
/* ---------------------------------------------------------------------------*/

/*
 * Get data from UART buffer
 */
uint8_t * uart_rxBuffer_get(void);
/* ---------------------------------------------------------------------------*/

/*
 * Store data in UART buffer
 */
void uart_rxBuffer_update(uint8_t data);
/* ---------------------------------------------------------------------------*/

/*
 * Reset UART Rx Index
 */
void uart_rxBuffer_index_reset(void);
/* ---------------------------------------------------------------------------*/

/*
 * Set UART data transfer status
 */
void uart_data_transfer_status_set(t_uartTransferStatus status);
/* ---------------------------------------------------------------------------*/

/*
 * Get UART data transfer status value
 */
t_uartTransferStatus uart_data_transfer_status_get(void);
/* ---------------------------------------------------------------------------*/

/*
 * Clear packet buffer
 */
void packetBuffer_reset(void);
/* ---------------------------------------------------------------------------*/


#endif /* UART_BUFFER_H_ */