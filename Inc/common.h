/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef COMMON_H_
#define COMMON_H_

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
#define OK     ((uint8_t) 1)
#define NOK    ((uint8_t) 0)

//#define RESET     ((uint8_t) 0)
//#define SET       ((uint8_t) 1)

/* ---------------------------------------------------------------------------
 * Types
 */
typedef enum
{
	INCOMPLETE = 0,
	COMPLETE
} t_uartTransferStatus;



/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */

#endif /* COMMON_H_ */
