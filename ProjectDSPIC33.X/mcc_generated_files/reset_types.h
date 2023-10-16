

#ifndef RESET_TYPES_H
#define	RESET_TYPES_H

/**
  Section: Type defines
 */ 
    
/** 
 * RCON error type enumerator. Supported types:
 * RESET_ERROR_RCON_TRAPR
 * RESET_ERROR_RCON_IOPUWR
 * RESET_ERROR_RCON_CM 
 * RESET_ERROR_RCON_WDTO_ISR
 */
typedef enum tagERROR_TYPE
{
    RESET_ERROR_RCON_TRAPR      = 1, /** A Trap Conflict Reset has occurred **/
    RESET_ERROR_RCON_IOPUWR     = 2, /** An illegal opcode detection, an illegal address mode or Uninitialized W register used as an
                             *   Address Pointer caused a Reset **/
    RESET_ERROR_RCON_CM         = 3, /** A Configuration Mismatch Reset has occurred **/
    RESET_ERROR_RCON_WDTO_ISR   = 4  /** WDT time-out has occurred **/
}RESET_TYPES;

/** 
 * RESET CAUSE Masks. Supported masks:
 * RESET_MASK_WDTO
 * RESET_MASK_SWR
 * RESET_MASK_EXTR
 * RESET_MASK_CM
 * RESET_MASK_IOPUWR
 * RESET_MASK_TRAPR
 */
typedef enum tagRESET_MASKS
{ 
  RESET_MASK_WDTO = 0x0010,
  RESET_MASK_SWR = 0x0040,
  RESET_MASK_EXTR = 0x0080, 
  RESET_MASK_CM = 0x0200, 
  RESET_MASK_IOPUWR = 0x4000, 
  RESET_MASK_TRAPR = 0x8000, 
} RESET_MASKS;

#endif	/* RESET_TYPES_H */


/*******************************************************************************

  !!! Deprecated Definitions and APIs !!!
  !!! These will not be supported in future releases !!!

*******************************************************************************/

#define ERR_RCON_TRAPR      RESET_ERROR_RCON_TRAPR
#define ERR_RCON_IOPUWR     RESET_ERROR_RCON_IOPUWR 
#define ERR_RCON_CM         RESET_ERROR_RCON_CM
#define ERR_RCON_WDTO_ISR   RESET_ERROR_RCON_WDTO_ISR

/**
 End of File
*/