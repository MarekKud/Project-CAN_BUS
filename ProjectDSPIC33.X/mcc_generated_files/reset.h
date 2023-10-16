

#ifndef RESET_H
#define	RESET_H

#include <stdint.h>
#include "reset_types.h"

/**
* Checks reset cause, flashes UI with an error code as a result.
* 
* Note: this function should be called before any use of CLRWDT
* since it has a side-effect of clearing the appropriate bits in the
* register showing reset cause (see DS70602B page 8-10)
*/
uint16_t RESET_GetCause(void);

/**
 * It handles the reset cause by clearing the cause register values.
 * Its a weak function user can override this function.
 * @return None
 * @example
 * <code>
 * RESET_CauseHandler();
 * </code>
 */
void RESET_CauseHandler(void);

/**
 * This function resets the reset cause register.
 * @return None
 * @example
 * <code>
 * RESET_CauseClearAll();
 * </code>
 */
void RESET_CauseClearAll();

#endif	/* RESET_H */
/**
 End of File
*/