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

/*
 * Used to set default path as No data path
 */
void path_init(void);
/* ---------------------------------------------------------------------------*/

/*
 * This function reads the sensor type from the header and sends the command to
 * initialise path for specific header
 */
uint8_t init_path_for_header_config(const uint8_t pBuffer[]);
/* ---------------------------------------------------------------------------*/

/*
 * Actual initialisation of a path depending
 * on the path type passed in
 */
uint8_t set_path(uint8_t pathType);
/* ---------------------------------------------------------------------------*/

/*
 * Read current path initialised
 */
uint8_t get_path(void);
/* ---------------------------------------------------------------------------*/

/*
 * De-init path passed in
 */
void clear_path(uint8_t pathType);
/* ---------------------------------------------------------------------------*/

/*
 * Transmit data using right path
 */
uint8_t transmit_sensor_data(uint8_t pathType, const uint8_t pBuffer[]);
/* ---------------------------------------------------------------------------*/

/*
 * Check data from buffer matches the current
 * initialised path and send command to transmit data
 */
uint8_t transmit_data_via_path(const uint8_t pBuffer[]);
/* ---------------------------------------------------------------------------*/

#endif /* PATH_H_ */
