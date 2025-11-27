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
    
    /*Place the init code */
    PWM_all_Start();
    
    Interruption_CMD_Enable();
    Interruption_CMD_Start();
    int vitesse = 100;
    char mes[1] ={0}; 
    
    while(1)
    {
        /* Place your application code here. */
        //delay(10000000);
        //UART_send("Denis", 5);
        Forward(vitesse);
        
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
