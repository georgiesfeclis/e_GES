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
typedef struct
{
	uint8_t cmd_name;
	uint8_t cmd_size;
}t_GEN5_RxData;

t_GEN5_RxData GEN5_RxData;
/* ---------------------------------------------------------------------------
 * Variables
 */

/* ---------------------------------------------------------------------------
 * Functions
 */
void Increment_RxCount(void);
uint16_t Get_RxCount(void);
void Reset_RxCount(void);
void rf_reset_cmd_handle(void);
void rf_event_clear_all(void);
uint8_t rf_event_sys_get(void);
uint8_t rf_event_event_get(void);





#endif /* GEN5_GEN5_COMMS_H_ */
