/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_SPI1_DRIVERS_H_
#define GEN5_SPI1_DRIVERS_H_

/* ---------------------------------------------------------------------------
 * Uses
 */

/* ---------------------------------------------------------------------------
 * Constants
 */

/* ---------------------------------------------------------------------------
 * Macros
 */

/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
void Activate_SPI1(void);
void SPI1_Rx_Callback(void);
void SPI1_TransferError_Callback(void);
void Configure_SPI1(void);

#endif /* GEN5_SPI1_DRIVERS_H_ */
