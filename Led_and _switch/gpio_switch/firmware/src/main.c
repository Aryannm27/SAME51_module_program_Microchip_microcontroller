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

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SYSTICK_TimerStart (  );
    SYSTICK_TimerPeriodSet ( 10000 );
    INT_GPO_PA14_Set();
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        
        
//        // this code is for getting internal button(pullup) input to blink internal led(which is pullup internally) of board
//        if(INT_GPI_PA15_Get()==0){
//            INT_GPO_PA14_Clear();
//            SYSTICK_DelayMs ( 1000 );
//        }
//        INT_GPO_PA14_Set();
//        SYSTICK_DelayMs ( 1000 );
//        
//        // this code is for getting external button(pullup) input to blink internal led(which is pullup internally) of board
//        if(EXT_GPI_PA01_Get()==0){
//        INT_GPO_PA15_Clear();
//        SYSTICK_DelayMs ( 1000 );
//        }
//        INT_GPO_PA15_Set();
//        SYSTICK_DelayMs ( 1000 );
//        
//         // this code is for getting internal button(pullup) input to blink external led of board
//        if(INT_GPI_PA15_Get()==0){
//        EXT_GPO_PA02_Set();
//        SYSTICK_DelayMs ( 1000 );
//        }
//        EXT_GPO_PA02_Clear();
//        SYSTICK_DelayMs ( 1000 );
//        
//         // this code is for getting external button(pullup) input to blink external led of board
//        if(EXT_GPI_PA01_Get()==0){
//        EXT_GPO_PA02_Set();
//        SYSTICK_DelayMs ( 1000 );
//        }
//        EXT_GPO_PA02_Clear();
//        SYSTICK_DelayMs ( 1000 );
        
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

