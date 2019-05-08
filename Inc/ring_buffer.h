/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

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
#define RING_BUFFER_SIZE            ((uint8_t) 8)
#define MAX_DATA_SIZE               ((uint8_t) 64)
//#define RING_BUFFER_MASK            ((uint8_t) (RING_BUFFER_SIZE-1))
/* ---------------------------------------------------------------------------
 * Types
 */
typedef struct
{
	uint8_t TailIndex;
	uint8_t HeadIndex;
	uint8_t SensorData[MAX_DATA_SIZE];
}t_RingBuffer;
/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

#endif /* RING_BUFFER_H_ */
