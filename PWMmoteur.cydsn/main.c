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
#include "PWM_all.h"



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


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /*Place the init code */
    PWM_all_Start();
    ADC_Pot_Start();
    ADC_Pot_StartConvert();
    StopWheels();
    int vitesse = 100;
    for(;;)
    {
        /* Place your application code here. */
        //vitesse = ADC_Pot_GetResult8();
        Forward(vitesse);
        //PWM_all_WriteCompare1(vitesse);
        //PWM_all_WriteCompare2(vitesse);
      
    }
   /*for(;;){
        //Get XBee value
        
        PWM_all_WriteCompare1(vitesse);
        PWM_all_WriteCompare2(vitesse);
        
    }*/
}



/* [] END OF FILE */
