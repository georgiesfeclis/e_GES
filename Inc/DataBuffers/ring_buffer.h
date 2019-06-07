/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef DATABUFFERS_RING_BUFFER_H_
#define DATABUFFERS_RING_BUFFER_H_

/* ---------------------------------------------------------------------------
 * Uses
 */
#include <DataBuffers/uart_buffer.h>
#include <stdint.h>
/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */
#define RING_BUFFER_SIZE            ((uint8_t) 8)
#define MAX_DATA_SIZE               ((uint8_t) 64)

/* ---------------------------------------------------------------------------
 * Types
 */
typedef struct
{
	uint8_t TailIndex;
	uint8_t HeadIndex;
	t_rxBuffer SensorData[RING_BUFFER_SIZE];
}t_RingBuffer;

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

/*
 * Initialise/Clear circular buffer
 */
void ring_buffer_clear(void);
/* ---------------------------------------------------------------------------*/

/*
 * Check if circular buffer is full, returns integer true/false
 */
int ring_buffer_is_full(void);
/* ---------------------------------------------------------------------------*/

/*
 * Check if circular buffer is empty, return integer true/false
 */
int ring_buffer_is_empty(void);
/* ---------------------------------------------------------------------------*/

/*
 * Write data to the ring buffer head, pass in buffer to the uart rxBuffer
 */
void ring_buffer_queue(const t_rxBuffer * pRxBuffer);
/* ---------------------------------------------------------------------------*/

/*
 * Read data from the ring buffer tail, return NOK if no data.
 */
uint8_t ring_buffer_dequeue(t_rxBuffer * pSensorData);
/* ---------------------------------------------------------------------------*/

#endif /* DATABUFFERS_RING_BUFFER_H_ */
