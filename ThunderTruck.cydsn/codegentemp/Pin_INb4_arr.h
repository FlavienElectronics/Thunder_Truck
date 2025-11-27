/*******************************************************************************
* File Name: Pin_INb4_arr.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_INb4_arr_H) /* Pins Pin_INb4_arr_H */
#define CY_PINS_Pin_INb4_arr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_INb4_arr_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_INb4_arr__PORT == 15 && ((Pin_INb4_arr__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pin_INb4_arr_Write(uint8 value);
void    Pin_INb4_arr_SetDriveMode(uint8 mode);
uint8   Pin_INb4_arr_ReadDataReg(void);
uint8   Pin_INb4_arr_Read(void);
void    Pin_INb4_arr_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pin_INb4_arr_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pin_INb4_arr_SetDriveMode() function.
     *  @{
     */
        #define Pin_INb4_arr_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pin_INb4_arr_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pin_INb4_arr_DM_RES_UP          PIN_DM_RES_UP
        #define Pin_INb4_arr_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pin_INb4_arr_DM_OD_LO           PIN_DM_OD_LO
        #define Pin_INb4_arr_DM_OD_HI           PIN_DM_OD_HI
        #define Pin_INb4_arr_DM_STRONG          PIN_DM_STRONG
        #define Pin_INb4_arr_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pin_INb4_arr_MASK               Pin_INb4_arr__MASK
#define Pin_INb4_arr_SHIFT              Pin_INb4_arr__SHIFT
#define Pin_INb4_arr_WIDTH              1u

/* Interrupt constants */
#if defined(Pin_INb4_arr__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pin_INb4_arr_SetInterruptMode() function.
     *  @{
     */
        #define Pin_INb4_arr_INTR_NONE      (uint16)(0x0000u)
        #define Pin_INb4_arr_INTR_RISING    (uint16)(0x0001u)
        #define Pin_INb4_arr_INTR_FALLING   (uint16)(0x0002u)
        #define Pin_INb4_arr_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pin_INb4_arr_INTR_MASK      (0x01u) 
#endif /* (Pin_INb4_arr__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_INb4_arr_PS                     (* (reg8 *) Pin_INb4_arr__PS)
/* Data Register */
#define Pin_INb4_arr_DR                     (* (reg8 *) Pin_INb4_arr__DR)
/* Port Number */
#define Pin_INb4_arr_PRT_NUM                (* (reg8 *) Pin_INb4_arr__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_INb4_arr_AG                     (* (reg8 *) Pin_INb4_arr__AG)                       
/* Analog MUX bux enable */
#define Pin_INb4_arr_AMUX                   (* (reg8 *) Pin_INb4_arr__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_INb4_arr_BIE                    (* (reg8 *) Pin_INb4_arr__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_INb4_arr_BIT_MASK               (* (reg8 *) Pin_INb4_arr__BIT_MASK)
/* Bypass Enable */
#define Pin_INb4_arr_BYP                    (* (reg8 *) Pin_INb4_arr__BYP)
/* Port wide control signals */                                                   
#define Pin_INb4_arr_CTL                    (* (reg8 *) Pin_INb4_arr__CTL)
/* Drive Modes */
#define Pin_INb4_arr_DM0                    (* (reg8 *) Pin_INb4_arr__DM0) 
#define Pin_INb4_arr_DM1                    (* (reg8 *) Pin_INb4_arr__DM1)
#define Pin_INb4_arr_DM2                    (* (reg8 *) Pin_INb4_arr__DM2) 
/* Input Buffer Disable Override */
#define Pin_INb4_arr_INP_DIS                (* (reg8 *) Pin_INb4_arr__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_INb4_arr_LCD_COM_SEG            (* (reg8 *) Pin_INb4_arr__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_INb4_arr_LCD_EN                 (* (reg8 *) Pin_INb4_arr__LCD_EN)
/* Slew Rate Control */
#define Pin_INb4_arr_SLW                    (* (reg8 *) Pin_INb4_arr__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_INb4_arr_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_INb4_arr__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_INb4_arr_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_INb4_arr__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_INb4_arr_PRTDSI__OE_SEL0        (* (reg8 *) Pin_INb4_arr__PRTDSI__OE_SEL0) 
#define Pin_INb4_arr_PRTDSI__OE_SEL1        (* (reg8 *) Pin_INb4_arr__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_INb4_arr_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_INb4_arr__PRTDSI__OUT_SEL0) 
#define Pin_INb4_arr_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_INb4_arr__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_INb4_arr_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_INb4_arr__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pin_INb4_arr__SIO_CFG)
    #define Pin_INb4_arr_SIO_HYST_EN        (* (reg8 *) Pin_INb4_arr__SIO_HYST_EN)
    #define Pin_INb4_arr_SIO_REG_HIFREQ     (* (reg8 *) Pin_INb4_arr__SIO_REG_HIFREQ)
    #define Pin_INb4_arr_SIO_CFG            (* (reg8 *) Pin_INb4_arr__SIO_CFG)
    #define Pin_INb4_arr_SIO_DIFF           (* (reg8 *) Pin_INb4_arr__SIO_DIFF)
#endif /* (Pin_INb4_arr__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pin_INb4_arr__INTSTAT)
    #define Pin_INb4_arr_INTSTAT            (* (reg8 *) Pin_INb4_arr__INTSTAT)
    #define Pin_INb4_arr_SNAP               (* (reg8 *) Pin_INb4_arr__SNAP)
    
	#define Pin_INb4_arr_0_INTTYPE_REG 		(* (reg8 *) Pin_INb4_arr__0__INTTYPE)
#endif /* (Pin_INb4_arr__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_INb4_arr_H */


/* [] END OF FILE */
