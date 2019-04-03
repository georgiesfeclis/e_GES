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
#include "main.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "init.h"
#include "path.h"
#include "header.h"
#include "G5Datagrams.h"
#include "uart_isr.h"
#include "common.h"

/* ----------------------------------------------------------------------------
 * Private types
 */

SPI_HandleTypeDef spi1;
UART_HandleTypeDef uart1;
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
extern uint8_t TransferStatus;
extern uint8_t PackID;
uint8_t TxData[] = "Hello, World!\n";
uint8_t SPI_Rx[10] = {0};
/* ----------------------------------------------------------------------------
 * Public functions
 */

int main(void)
{

  /* MCU Configuration----------------------------------------------------------*/
  /* Reset of all peripherals, Initialises the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
//  MX_SPI1_Init();
  MX_USART1_UART_Init();

  HAL_UART_Receive_IT(&uart1, &RxData[0], 1);

  path_init();

  /* Infinite loop */
  while (1)
  {

	  HAL_SPI_Receive(&spi1, &SPI_Rx[0], 10, HAL_MAX_DELAY);
//	  HAL_UART_Transmit(&uart1, &TxData[0], 20, HAL_MAX_DELAY);
//	  HAL_Delay(500);

	  if(TransferStatus != 0)
	  {
		  if(PackID == CONFIG_DATA)
		  {
			  init_path_for_header_config(&RxBuffer[0]);

		  }
		  else if(PackID == SENSOR_DATA)
		  {
			  assign_g5_data_to_datagram(&RxBuffer[0]);
		  }
	  }

  }

}
