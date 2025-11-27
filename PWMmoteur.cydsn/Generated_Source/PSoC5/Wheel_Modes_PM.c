/*******************************************************************************
* File Name: Wheel_Modes_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Wheel_Modes.h"

/* Check for removal by optimization */
#if !defined(Wheel_Modes_Sync_ctrl_reg__REMOVED)

static Wheel_Modes_BACKUP_STRUCT  Wheel_Modes_backup = {0u};

    
/*******************************************************************************
* Function Name: Wheel_Modes_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheel_Modes_SaveConfig(void) 
{
    Wheel_Modes_backup.controlState = Wheel_Modes_Control;
}


/*******************************************************************************
* Function Name: Wheel_Modes_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Wheel_Modes_RestoreConfig(void) 
{
     Wheel_Modes_Control = Wheel_Modes_backup.controlState;
}


/*******************************************************************************
* Function Name: Wheel_Modes_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheel_Modes_Sleep(void) 
{
    Wheel_Modes_SaveConfig();
}


/*******************************************************************************
* Function Name: Wheel_Modes_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Wheel_Modes_Wakeup(void)  
{
    Wheel_Modes_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
