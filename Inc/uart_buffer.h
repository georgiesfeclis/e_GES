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
void uart_rxBuffer_init(void);
/*
 * Get data from UART buffer
 */
uint8_t * uart_rxBuffer_get(void);

void uart_rxBuffer_update(uint8_t data);

void uart_rxBuffer_index_reset(void);

void uart_data_transfer_status_set(t_uartTransferStatus status);
t_uartTransferStatus uart_data_transfer_status_get(void);
void PacketBuffer_Reset(void);


#endif /* UART_BUFFER_H_ */
