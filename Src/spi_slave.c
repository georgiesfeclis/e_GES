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
#include "spi_slave.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "Gen5_init.h"
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
/* ----------------------------------------------------------------------------
 * Private types
 */

/* ----------------------------------------------------------------------------
 * Private defines
 */

/* ----------------------------------------------------------------------------
 * Private macros
 */

/* ----------------------------------------------------------------------------
 * Private variables 
 */
static uint8_t steve = 0;
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

uint8_t counter(void)
{
	return steve++;
}


void spi_isr_init(void)
{
	HAL_SPI_Transmit_IT(&spi1, &steve, 1);
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	HAL_SPI_Transmit_IT(&spi1, &steve, 1);
}
