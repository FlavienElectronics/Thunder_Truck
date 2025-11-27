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

void delay(uint32_t cycle){
    for(uint32_t i = 0; i < cycle; i++){
        for(uint32_t y = 0; y < 1000; y++){
        }
    }
}

#define Mot1_mask 0x03
#define Mot2_mask 0x0C
#define Mot3_mask 0x30
#define Mot4_mask 0xC0

void StopWheels(){
    Wheel_Modes_Write(0);
}

void Spin_Right(int Vitesse){
    Wheel_Modes_Write(0xAA);
    PWM_all_WriteCompare1(Vitesse);
    PWM_all_WriteCompare2(Vitesse);
}
void Spin_Left(int Vitesse){
    Wheel_Modes_Write(0x55);
    PWM_all_WriteCompare1(Vitesse);
    PWM_all_WriteCompare2(Vitesse);
}
void Forward(int Vitesse){
    Wheel_Modes_Write(0x96);
    PWM_all_WriteCompare1(Vitesse);
    PWM_all_WriteCompare2(Vitesse);
}
void Backward(int Vitesse){
    Wheel_Modes_Write(0x69);
    PWM_all_WriteCompare1(Vitesse);
    PWM_all_WriteCompare2(Vitesse);
}
void ForwardRight(int Vitesse){
    Wheel_Modes_Write(0x96);
    int tempVitD = Vitesse-30;
    int tempVitG = Vitesse;
    if (tempVitD<0){
        tempVitD = 0;
        tempVitG = 30;
    }
    PWM_all_WriteCompare1(tempVitD);
    PWM_all_WriteCompare2(tempVitG);
}
void ForwardLeft(int Vitesse){
    Wheel_Modes_Write(0x96);
    int tempVitD = Vitesse;
    int tempVitG = Vitesse-30;
    if (tempVitG<0){
        tempVitG = 0;
        tempVitD = 30;
    }
    PWM_all_WriteCompare1(tempVitD);
    PWM_all_WriteCompare2(tempVitG);
}
void BackwardRight(int Vitesse){
    Wheel_Modes_Write(0x69);
    int tempVitD = Vitesse-30;
    int tempVitG = Vitesse;
    if (tempVitD<0){
        tempVitD = 0;
        tempVitG = 30;
    }
    PWM_all_WriteCompare1(tempVitD);
    PWM_all_WriteCompare2(tempVitG);
}
void BackwardLeft(int Vitesse){
    Wheel_Modes_Write(0x69);
    int tempVitD = Vitesse;
    int tempVitG = Vitesse-30;
    if (tempVitG<0){
        tempVitG = 0;
        tempVitD = 30;
    }
    PWM_all_WriteCompare1(tempVitD);
    PWM_all_WriteCompare2(tempVitG);
}



/* [] END OF FILE */
