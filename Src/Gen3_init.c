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
#include "Gen3_init.h"
/* ----------------------------------------------------------------------------
 * Uses
 */
#include "init.h"
/* ----------------------------------------------------------------------------
 * Private types
 */
DAC_HandleTypeDef dac;
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

/* ---------------------------------------------------------------------------*/
void gen3_periph_init(void)
{
	gen3_GPIO_init();
	DAC_Init();
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void gen3_periph_deinit(void)
{
	HAL_GPIO_WritePin(GPIOB, G3_COMMS_Pin, GPIO_PIN_RESET);
	HAL_DAC_Init(&dac);
}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void DAC_Init(void)
{

  DAC_ChannelConfTypeDef sConfig;

    /**DAC Initialization
    */
  dac.Instance = DAC;
  if (HAL_DAC_Init(&dac) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**DAC channel OUT1 config
    */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&dac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/
void gen3_GPIO_init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, G3_COMMS_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : G3_COMMS_Pin */
	GPIO_InitStruct.Pin = G3_COMMS_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(G3_COMMS_GPIO_Port, &GPIO_InitStruct);
}
/* ---------------------------------------------------------------------------*/
