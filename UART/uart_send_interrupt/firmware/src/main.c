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

char send='S';
int flag=0;

void callback(uintptr_t context){
    flag=1;
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SERCOM4_USART_WriteCallbackRegister(callback,0);
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        SERCOM4_USART_Write( &send, sizeof(send) );
        if(flag==1){
            LED_Set();
            for(int i=0;i<10000000;i++);
            LED_Clear();
            for(int i=0;i<10000000;i++);
            flag=0;
        }
        printf("\ndevice1 send = ");
        SERCOM5_USART_Write( &send, sizeof(send) );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

