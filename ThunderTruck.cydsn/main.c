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

void delay(uint32_t cycle){
    for(uint32_t i = 0; i < cycle; i++){
        for(uint32_t y = 0; y < 1000; y++){
        }
    }
}

char Char_main;
enum Direction
{
    HAUT = 0x7A,        // z minuscule
    BAS = 0x73,         // s minuscule
    GAUCHE = 0x71,      // q minuscule
    DROITE = 0x64,        // d minuscule
    ACCELERATION_EXPLOSIVE = 0x20 // espace
};

uint8_t retourne_rien()
{
    return(42);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    PWM_test_Start();
    
    UART_test_Init();
    UART_test_Enable();
    UART_test_Start();
    
    Interruption_CMD_Enable();
    Interruption_CMD_Start();
    char mes[1] ={0}; 
    
    while(1)
    {
        /* Place your application code here. */
        //delay(10000000);
        //UART_send("Denis", 5);
        
        if(Char_main == DROITE)
        {
            UART_test_WriteTxData(1);
            Char_main = 0;
        }
        if(Char_main == GAUCHE)
        {
            UART_test_WriteTxData(2);
            Char_main = 0;
        }
        if(Char_main == HAUT)
        {
            UART_test_WriteTxData(3);
            Char_main = 0;
        }
        if(Char_main == BAS)
        {
            UART_test_WriteTxData(4);
            Char_main = 0;
        }
        if(Char_main == ACCELERATION_EXPLOSIVE)
        {
            UART_test_WriteTxData(5);
            Char_main = 0;
        }
    }
}

/* [] END OF FILE */
