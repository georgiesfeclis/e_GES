/**
 * Copyright (c) 2019 bf1systems
 *
 * @file
 * @author: Georgiana-Elena Sfeclis
 * One line summary
 *
 * Multi line overview here if useful.
 */

#ifndef GEN5_GEN5_COMMS_H_
#define GEN5_GEN5_COMMS_H_

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

#define BIT_SET        1
#define BIT_RESET      0
/* ---------------------------------------------------------------------------
 * Types
 */

/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
void rf_reset_cmd_handle(void);
void rf_event_clear_all(void);
uint8_t rf_event_sys_get(void);
uint8_t rf_event_event_get(void);





#endif /* GEN5_GEN5_COMMS_H_ */
