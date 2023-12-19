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
//char send='M';
//char receive;
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    char send[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    char receive[sizeof(send)];
    int i=0;

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        SERCOM0_I2C_WriteRead(5, (uint8_t*) &send[i], (uint32_t) sizeof(send[0]),(uint8_t*) &receive[i], (uint32_t)sizeof(send[0]));
        // below code is for individual code
//        SERCOM0_I2C_Write(5, (uint8_t*) &send[i], (uint32_t) sizeof(send[0]));
//        SERCOM0_I2C_Read(5, (uint8_t*) &receive[i], (uint32_t)sizeof(send[0]));
        i++;
        if(i>=sizeof(send)){
            SERCOM5_USART_Write( receive, sizeof(receive) );
            i=0;
        }
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

