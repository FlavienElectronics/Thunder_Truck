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

#include "utilities.h"

void UART_send(char * msg, uint8_t size){
    uint8 cpt;           /* Data sent on the serial port */

    CyGlobalIntEnable; 

    UART_test_Start();     /* Enabling the UART */
        
    for(cpt = 0; cpt <= size; cpt++)
    {
        UART_test_WriteTxData(msg[cpt]); /* Sending the data */
    }
    UART_test_WriteTxData('\0');
}

uint8_t UART_read(char * buffer, uint16_t size)
{   
    char8 ch = '\0';       /* Data received from the Serial port */
    int cpt = 0;
    
    while(ch != '\n' || cpt > size)
    {
        /* Check the UART status */
        ch = UART_test_GetChar();

        /* If byte received */
        if(ch > 0u)
        {
            buffer[cpt] = ch;
            cpt++;
        }
    }
    
    return 0;
}


/* [] END OF FILE */
