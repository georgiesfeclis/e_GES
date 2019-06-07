/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef DATABUFFERS_UART_BUFFER_H_
#define DATABUFFERS_UART_BUFFER_H_

/* ---------------------------------------------------------------------------
 * Uses
 */

#include "common.h"

/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */
#define UART_RX_BUFFER_SIZE ((uint8_t) 64)
#define BYTE_MASK            0xFFUL
/* ---------------------------------------------------------------------------
 * Types
 */
typedef enum
{
	IDLE_STATE = 0,
	RXDATA_STATE,
}t_rxType;


typedef struct
{
	uint8_t DataSize;
	uint8_t PacketBuffer[UART_RX_BUFFER_SIZE];
	uint8_t Checksum;
}t_rxBuffer;
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
t_rxBuffer * uart_rxBuffer_get(void);
/* ---------------------------------------------------------------------------*/

/*
 * Store data in UART buffer
 */
void uart_rxBuffer_update(uint8_t data);
/* ---------------------------------------------------------------------------*/

void uart_rxBuffer_size_byte_set(uint8_t sizeByte);
uint8_t uart_rxBuffer_size_byte_get(void);
void uart_rxBuffer_crc_byte_set(uint8_t sizeByte);
uint8_t uart_rxBuffer_crc_byte_get(void);
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
uint8_t process_rx_data(const uint8_t data);
uint8_t rx_buffer_crc_calculation(void);


#endif /* DATABUFFERS_UART_BUFFER_H_ */
