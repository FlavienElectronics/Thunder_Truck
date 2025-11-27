/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "utilities.h"


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    PWM_test_Start();
    
    UART_test_Init();
    UART_test_Enable();
    UART_test_Start();
    
    /*Place the init code */
    PWM_all_Start();
    
    Interruption_CMD_Enable();
    Interruption_CMD_Start();
    
    while(1)
    {
        /* Place your application code here. */
        //delay(10000000);
        //UART_send("Denis", 5);
        

        
    }
}

/* [] END OF FILE */
