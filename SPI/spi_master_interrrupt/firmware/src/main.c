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
int flag = 0;

void CallBack(uintptr_t context){
    flag=1;
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SERCOM1_SPI_CallbackRegister( &CallBack, (uintptr_t)NULL);

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        SS_Clear();
        SERCOM1_SPI_WriteRead (send, sizeof(send), receive, sizeof(send));
//        SERCOM1_SPI_Write(send, sizeof(send));
//        SERCOM1_SPI_Read(receive, sizeof(send));
        SS_Set();
        
        if(flag==1){
            LED_Set();
            for(int i=0;i<10000000;i++);
            LED_Clear();
            for(int i=0;i<10000000;i++);
            flag=0;
        }
        
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

