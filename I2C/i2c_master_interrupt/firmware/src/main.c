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
int flag=0;
void callback(){
    flag=1;
}
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SERCOM2_I2C_CallbackRegister( callback, 0);

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        SERCOM2_I2C_WriteRead( 5, (uint8_t *)send, (uint32_t)sizeof(send), (uint8_t *)receive, (uint32_t)sizeof(send));
        
        // below code is for individual code

//        SERCOM2_I2C_Read(0X27, (uint8_t*)send, (uint32_t)sizeof(send));
//        SERCOM2_I2C_Write(0X27, (uint8_t*)receive, (uint32_t)sizeof(send));
        
        if(flag==1){
            LED_Set();
            for(int i=0;i<10000000;i++);
            LED_Clear();
            for(int i=0;i<10000000;i++);
            flag=0;
        }
        
//        printf("\nmaster send = %s\r",send);
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

