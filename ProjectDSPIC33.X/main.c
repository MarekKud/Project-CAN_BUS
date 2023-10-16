
/**
  Section: Included Files
*/
#define FCY  CLOCK_PeripheralFrequencyGet() 
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/usb/usb_device.h"
#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/usb/usb_ch9.h"
#include "mcc_generated_files/usb/usb_common.h"
#include "mcc_generated_files/usb/usb_device_config.h"
#include "mcc_generated_files/usb/usb_device_config.h"
#include "mcc_generated_files/usb/usb_hal.h"
#include "mcc_generated_files/usb/usb_hal_dspic33e.h"
#include "mcc_generated_files/interrupt_manager.h"
#include <libpic30.h>
#include "mcc_generated_files/clock.h"
//#define USB_HAL_DSPIC33E_H
/*
                         Main application
 */
void MCC_USB_CDC_DemoTasks(void);
static uint8_t readBuffer[64];
static uint8_t writeBuffer[64];

int main(void)
{

   

    // initialize the device
   SYSTEM_Initialize();
   
    while (1)
    {
        
        MCC_USB_CDC_DemoTasks();
        // Add your application code
       
       
         IO_RE4_Toggle();
         //__delay_ms(10);
         IO_RE2_Toggle();
    }
    return 1; 
}
/**
 End of File
*/

void MCC_USB_CDC_DemoTasks(void)
{
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    if( USBIsDeviceSuspended()== true )
    {
        return;
    }

    if( USBUSARTIsTxTrfReady() == true)
    {
        uint8_t i;
        uint8_t numBytesRead;

        numBytesRead = getsUSBUSART(readBuffer, sizeof(readBuffer));

        for(i=0; i<numBytesRead; i++)
        {
            switch(readBuffer[i])
            {
                /* echo line feeds and returns without modification. */
                case 0x0A:
                case 0x0D:
                    writeBuffer[i] = readBuffer[i];
                    break;

                /* all other characters get +1 (e.g. 'a' -> 'b') */
                default:
                    writeBuffer[i] = readBuffer[i];
                    break;
            }
        }

        if(numBytesRead > 0)
        {
            putUSBUSART(writeBuffer,numBytesRead);
        }
    }

    CDCTxService();
    
}
