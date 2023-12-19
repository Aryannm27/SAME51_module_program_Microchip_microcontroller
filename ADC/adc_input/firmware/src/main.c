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
uint16_t adc_result;
bool adc_status;
int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SYSTICK_TimerStart (  );
    SYSTICK_TimerPeriodSet ( 10000 );
    ADC0_ChannelSelect( ADC_POSINPUT_AIN0, ADC_NEGINPUT_GND );
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
        ADC0_Enable(  );
        ADC0_ConversionStart(  );
        adc_result=ADC0_ConversionResultGet(  );
        adc_status=ADC0_ConversionStatusGet(  );
        printf("%d %d \n",adc_result,adc_status);
        ADC0_Disable(  );
        SYSTICK_DelayMs ( 1000 );
        adc_status=ADC0_ConversionStatusGet(  );
        adc_result=ADC0_LastConversionResultGet(  );
        printf("%d %d \n",adc_result,adc_status);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

