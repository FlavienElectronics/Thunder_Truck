/*******************************************************************************
* File Name: PWM_all_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_all.h"

static PWM_all_backupStruct PWM_all_backup;


/*******************************************************************************
* Function Name: PWM_all_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_all_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_all_SaveConfig(void) 
{

    #if(!PWM_all_UsingFixedFunction)
        #if(!PWM_all_PWMModeIsCenterAligned)
            PWM_all_backup.PWMPeriod = PWM_all_ReadPeriod();
        #endif /* (!PWM_all_PWMModeIsCenterAligned) */
        PWM_all_backup.PWMUdb = PWM_all_ReadCounter();
        #if (PWM_all_UseStatus)
            PWM_all_backup.InterruptMaskValue = PWM_all_STATUS_MASK;
        #endif /* (PWM_all_UseStatus) */

        #if(PWM_all_DeadBandMode == PWM_all__B_PWM__DBM_256_CLOCKS || \
            PWM_all_DeadBandMode == PWM_all__B_PWM__DBM_2_4_CLOCKS)
            PWM_all_backup.PWMdeadBandValue = PWM_all_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_all_KillModeMinTime)
             PWM_all_backup.PWMKillCounterPeriod = PWM_all_ReadKillTime();
        #endif /* (PWM_all_KillModeMinTime) */

        #if(PWM_all_UseControl)
            PWM_all_backup.PWMControlRegister = PWM_all_ReadControlRegister();
        #endif /* (PWM_all_UseControl) */
    #endif  /* (!PWM_all_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_all_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_all_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_all_RestoreConfig(void) 
{
        #if(!PWM_all_UsingFixedFunction)
            #if(!PWM_all_PWMModeIsCenterAligned)
                PWM_all_WritePeriod(PWM_all_backup.PWMPeriod);
            #endif /* (!PWM_all_PWMModeIsCenterAligned) */

            PWM_all_WriteCounter(PWM_all_backup.PWMUdb);

            #if (PWM_all_UseStatus)
                PWM_all_STATUS_MASK = PWM_all_backup.InterruptMaskValue;
            #endif /* (PWM_all_UseStatus) */

            #if(PWM_all_DeadBandMode == PWM_all__B_PWM__DBM_256_CLOCKS || \
                PWM_all_DeadBandMode == PWM_all__B_PWM__DBM_2_4_CLOCKS)
                PWM_all_WriteDeadTime(PWM_all_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_all_KillModeMinTime)
                PWM_all_WriteKillTime(PWM_all_backup.PWMKillCounterPeriod);
            #endif /* (PWM_all_KillModeMinTime) */

            #if(PWM_all_UseControl)
                PWM_all_WriteControlRegister(PWM_all_backup.PWMControlRegister);
            #endif /* (PWM_all_UseControl) */
        #endif  /* (!PWM_all_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_all_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_all_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_all_Sleep(void) 
{
    #if(PWM_all_UseControl)
        if(PWM_all_CTRL_ENABLE == (PWM_all_CONTROL & PWM_all_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_all_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_all_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_all_UseControl) */

    /* Stop component */
    PWM_all_Stop();

    /* Save registers configuration */
    PWM_all_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_all_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_all_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_all_Wakeup(void) 
{
     /* Restore registers values */
    PWM_all_RestoreConfig();

    if(PWM_all_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_all_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
