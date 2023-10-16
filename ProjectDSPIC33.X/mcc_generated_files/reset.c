

#include <stdbool.h>
#include <stdint.h>
#include "xc.h"
#include "reset.h"

/**
 Section: Local Variables
*/

/**
 Section: Function prototypes
*/
static bool RESET_CauseFromSoftware(uint16_t resetCause);
static bool RESET_CauseFromWatchdogTimer(uint16_t resetCause);
static bool RESET_CauseFromConfigurationMismatch(uint16_t resetCause);
static bool RESET_CauseFromIllegalOpcode(uint16_t resetCause);
static bool RESET_CauseFromExternal(uint16_t resetCause);
static bool RESET_CauseFromTrap(uint16_t resetCause);
static void RESET_CauseClear(RESET_MASKS resetFlagMask);

uint16_t RESET_GetCause(void)
{
    return RCON;
}

void __attribute__ ((weak)) RESET_CauseHandler(void)
{
    uint16_t resetCause = RESET_GetCause();
    if(RESET_CauseFromTrap(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_TRAPR); 
      //Do something 
    }
    if(RESET_CauseFromIllegalOpcode(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_IOPUWR); 
      //Do something 
    }
    if(RESET_CauseFromConfigurationMismatch(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_CM); 
      //Do something 
    }
    if(RESET_CauseFromExternal(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_EXTR); 
      //Do something 
    }
    if(RESET_CauseFromSoftware(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_SWR); 
      //Do something 
    }
    if(RESET_CauseFromWatchdogTimer(resetCause))
    { 
      RESET_CauseClear(RESET_MASK_WDTO); 
      //Do something 
    }
}

static bool RESET_CauseFromTrap(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_TRAPR)
    { 
      resetStatus = true; 
    }
    return resetStatus;
}

static bool RESET_CauseFromIllegalOpcode(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_IOPUWR)
    { 
      resetStatus = true; 
    }
    return resetStatus;
}

static bool RESET_CauseFromConfigurationMismatch(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_CM)
    { 
      resetStatus = true; 
    }
    return resetStatus;
}

static bool RESET_CauseFromExternal(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_EXTR)
    { 
      resetStatus = true; 
    }
    return resetStatus;
}

static bool RESET_CauseFromSoftware(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_SWR)
    { 
      resetStatus = true; 
    }
    return resetStatus;
}

static bool RESET_CauseFromWatchdogTimer(uint16_t resetCause)
{
    bool resetStatus = false;
    if(resetCause & RESET_MASK_WDTO)
    { 
      resetStatus = true;
    }
    return resetStatus;
}

static void RESET_CauseClear(RESET_MASKS resetFlagMask)
{ 
     RCON = RCON & (~resetFlagMask); 
} 

void RESET_CauseClearAll()
{ 
    RCON = 0x00; 
}
/**
 End of File
*/