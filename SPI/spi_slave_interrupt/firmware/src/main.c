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
int flag = 0;

void CallBack(uintptr_t context){
     if( SERCOM1_SPI_ErrorGet() == SPI_SLAVE_ERROR_NONE )
            {
                   flag =1;
                   printf("\r\nflag = %d\n",flag);
//                   SERCOM1_SPI_Write( send, sizeof(send) );
                   
            }
     
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SERCOM1_SPI_CallbackRegister(CallBack, 0 );
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        SERCOM1_SPI_Read( receive, sizeof(receive));
//        SERCOM1_SPI_Write( send, sizeof(send) );
        
        if(flag==1){
            LED_Set();
            for(int i=0;i<10000000;i++);
            LED_Clear();
            for(int i=0;i<10000000;i++);
            flag=0;
        }
        
        printf("\nslave send = %s\r",send);
        printf("\nslave receive = ");
        SERCOM5_USART_Write( receive, sizeof(send) );
       
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

