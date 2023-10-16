
/**
    Section: Includes
*/
#include <xc.h>

/**
    void INTERRUPT_Initialize (void)
*/
void INTERRUPT_Initialize (void)
{
    //    USBI: USB1 Interrupt
    //    Priority: 1
        IPC21bits.USB1IP = 1;
}