/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef PATH_H_
#define PATH_H_

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

#define NO_DATA_PATH_FLAG        ((uint8_t) 0x00)
#define GEN2_PATH_FLAG           ((uint8_t) 0x04)
#define GEN25_PATH_FLAG          ((uint8_t) 0x08)
#define GEN3_PATH_FLAG           ((uint8_t) 0x0C)
#define GEN5_PATH_FLAG           ((uint8_t) 0x10)
#define RF_PATH_FLAG             ((uint8_t) 0x14)
#define SPI1_MASTER_FLAG         ((uint8_t) 0x18)

/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

void path_init(void);
uint8_t init_path_for_header_config(uint8_t * pBuffer);
uint8_t set_path(uint8_t pathType);
uint8_t get_path(void);
void clear_path(uint8_t pathType);
uint8_t transmit_sensor_data(uint8_t pathType, uint8_t * pBuffer);
uint8_t transmit_data_via_path(uint8_t * pBuffer);

#endif /* PATH_H_ */
