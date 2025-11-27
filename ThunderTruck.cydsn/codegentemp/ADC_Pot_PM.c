/*******************************************************************************
* File Name: ADC_Pot_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Pot.h"


/***************************************
* Local data allocation
***************************************/

static ADC_Pot_BACKUP_STRUCT  ADC_Pot_backup =
{
    ADC_Pot_DISABLED
};


/*******************************************************************************
* Function Name: ADC_Pot_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Pot_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Pot_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Pot_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Pot_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_Pot_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Pot_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_Pot_Sleep(void)
{
    if((ADC_Pot_PWRMGR_SAR_REG  & ADC_Pot_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_Pot_SAR_CSR0_REG & ADC_Pot_SAR_SOF_START_CONV) != 0u)
        {
            ADC_Pot_backup.enableState = ADC_Pot_ENABLED | ADC_Pot_STARTED;
        }
        else
        {
            ADC_Pot_backup.enableState = ADC_Pot_ENABLED;
        }
        ADC_Pot_Stop();
    }
    else
    {
        ADC_Pot_backup.enableState = ADC_Pot_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_Pot_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_Pot_Sleep() was called. If the component was enabled before the
*  ADC_Pot_Sleep() function was called, the
*  ADC_Pot_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Pot_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_Pot_Wakeup(void)
{
    if(ADC_Pot_backup.enableState != ADC_Pot_DISABLED)
    {
        ADC_Pot_Enable();
        #if(ADC_Pot_DEFAULT_CONV_MODE != ADC_Pot__HARDWARE_TRIGGER)
            if((ADC_Pot_backup.enableState & ADC_Pot_STARTED) != 0u)
            {
                ADC_Pot_StartConvert();
            }
        #endif /* End ADC_Pot_DEFAULT_CONV_MODE != ADC_Pot__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
