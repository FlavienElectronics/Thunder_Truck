/*******************************************************************************
* File Name: Interruption_CMD.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Interruption_CMD_H)
#define CY_ISR_Interruption_CMD_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Interruption_CMD_Start(void);
void Interruption_CMD_StartEx(cyisraddress address);
void Interruption_CMD_Stop(void);

CY_ISR_PROTO(Interruption_CMD_Interrupt);

void Interruption_CMD_SetVector(cyisraddress address);
cyisraddress Interruption_CMD_GetVector(void);

void Interruption_CMD_SetPriority(uint8 priority);
uint8 Interruption_CMD_GetPriority(void);

void Interruption_CMD_Enable(void);
uint8 Interruption_CMD_GetState(void);
void Interruption_CMD_Disable(void);

void Interruption_CMD_SetPending(void);
void Interruption_CMD_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Interruption_CMD ISR. */
#define Interruption_CMD_INTC_VECTOR            ((reg32 *) Interruption_CMD__INTC_VECT)

/* Address of the Interruption_CMD ISR priority. */
#define Interruption_CMD_INTC_PRIOR             ((reg8 *) Interruption_CMD__INTC_PRIOR_REG)

/* Priority of the Interruption_CMD interrupt. */
#define Interruption_CMD_INTC_PRIOR_NUMBER      Interruption_CMD__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Interruption_CMD interrupt. */
#define Interruption_CMD_INTC_SET_EN            ((reg32 *) Interruption_CMD__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Interruption_CMD interrupt. */
#define Interruption_CMD_INTC_CLR_EN            ((reg32 *) Interruption_CMD__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Interruption_CMD interrupt state to pending. */
#define Interruption_CMD_INTC_SET_PD            ((reg32 *) Interruption_CMD__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Interruption_CMD interrupt. */
#define Interruption_CMD_INTC_CLR_PD            ((reg32 *) Interruption_CMD__INTC_CLR_PD_REG)


#endif /* CY_ISR_Interruption_CMD_H */


/* [] END OF FILE */
