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

char send[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
char receive[sizeof(send)];



int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
//    SPI_TRANSFER_SETUP setup;
//    setup.clockFrequency = 1000000;
//    setup.clockPhase = SPI_CLOCK_PHASE_TRAILING_EDGE;
//    setup.clockPolarity = SPI_CLOCK_POLARITY_IDLE_LOW;
//    setup.dataBits = SPI_DATA_BITS_8;
//    
//    SERCOM1_SPI_TransferSetup(&setup, 2000000);
    
    
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        SS_Clear();
        SERCOM1_SPI_WriteRead (send, sizeof(send), receive, sizeof(send));
        SS_Set();
        
        printf("\nmaster send = %s\r",send);
        printf("\nmaster receive = ");
        SERCOM5_USART_Write( receive, sizeof(send) );
        printf("\r");
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

