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

void UART_send(char * msg, uint8_t size);
uint8_t UART_read(char * buffer, uint16_t size);

enum Direction
{
    HAUT = 0x7A,        // z minuscule
    BAS = 0x73,         // s minuscule
    GAUCHE = 0x71,      // q minuscule
    DROITE = 0x64,        // d minuscule
    ACCELERATION_EXPLOSIVE = 0x20 // espace
};


void delay(uint32_t cycle);
void StopWheels();
void Spin_Left(int Vitesse);
void Spin_Right(int Vitesse);
void Forward(int Vitesse);
void Backward(int Vitesse);
void ForwardRight(int Vitesse);
void ForwardLeft(int Vitesse);
void BackwardRight(int Vitesse);
void BackwardLeft(int Vitesse);








/* [] END OF FILE */
