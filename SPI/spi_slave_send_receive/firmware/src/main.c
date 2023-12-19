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

char send[]="abcdefghijklmnopqrstuvwxyz\n";
char receive[sizeof(send)];


int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        SERCOM1_SPI_Read( receive, sizeof(receive));
        SERCOM1_SPI_Write( send, sizeof(send) );
        
//        for(int i=0;i<sizeof(send);i++){
//            SERCOM1_SPI_Read( &receive[i], sizeof(receive[0]));
//            SERCOM1_SPI_Write( &send[i], sizeof(send[0]) );
//        }
        
        
        printf("\nslave send = %s\r",send);
        printf("\nslave receive = ");
        SERCOM5_USART_Write( receive, sizeof(send) );
        printf("\r");
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

