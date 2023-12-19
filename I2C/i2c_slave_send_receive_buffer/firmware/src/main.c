/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
uint8_t send[]="abcdefghijklmnopqrstuvwxyz\n";
uint8_t receive[sizeof(send)];

//uint8_t send='S';
//uint8_t receive;
int i=0;
int j=0;

bool callback(SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle){
    SERCOM0_I2C_WriteByte(send[i]);
    if(SERCOM0_I2C_IsBusy()==0){
            i++;
        }
        if(i>=sizeof(send)){
           i=0;
        }
    if(SERCOM0_I2C_ErrorGet() != SERCOM_I2C_SLAVE_ERROR_ALL){
        return true;      
    }
    return false;
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    SERCOM0_I2C_CallbackRegister(callback, 0);
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        receive[j] =  SERCOM0_I2C_ReadByte();
        j++;
        if(j>=sizeof(send)){
           SERCOM5_USART_Write( receive, sizeof(receive) );
           j=0;
        }
        
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

