/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */


/* ----------------------------------------------------------------------------
 * Implements
 */
#include "ring_buffer.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "common.h"
#include "uart_buffer.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
static t_RingBuffer sensorData;
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
void ring_buffer_clear(void)
{
	sensorData.HeadIndex = 0;
	sensorData.TailIndex = 0;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
int ring_buffer_is_full(void)
{
	return sensorData.TailIndex == ((sensorData.HeadIndex + 1) % RING_BUFFER_SIZE);
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
int ring_buffer_is_empty(void)
{
	return sensorData.HeadIndex == sensorData.TailIndex;
}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
void ring_buffer_queue(const t_rxBuffer * const pRxBuffer)
{

	if(ring_buffer_is_full())
	{
		/* If buffer is full, overwrite the oldest byte of data */
		sensorData.TailIndex = (uint8_t)((sensorData.TailIndex + 1) % RING_BUFFER_SIZE);
	}

		sensorData.SensorData[sensorData.HeadIndex] = *pRxBuffer;

	sensorData.HeadIndex = (uint8_t)((sensorData.HeadIndex + 1) % RING_BUFFER_SIZE);

}
/* ----------------------------------------------------------------------------*/

/* ----------------------------------------------------------------------------*/
uint8_t ring_buffer_dequeue(t_rxBuffer * pSensorData)
{
	uint8_t retVal;

	if(ring_buffer_is_empty())
	{
		/* no items to be returned */
		retVal = NOK;
	}
	else
	{
		*pSensorData = sensorData.SensorData[sensorData.TailIndex];

		sensorData.TailIndex = (uint8_t)((sensorData.TailIndex + 1) % RING_BUFFER_SIZE);

		retVal = OK;
	}

	return retVal;
}
/* ----------------------------------------------------------------------------*/


