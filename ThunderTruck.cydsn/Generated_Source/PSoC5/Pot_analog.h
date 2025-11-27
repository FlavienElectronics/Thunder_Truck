/*******************************************************************************
* File Name: Pot_analog.h  
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

#if !defined(CY_PINS_Pot_analog_H) /* Pins Pot_analog_H */
#define CY_PINS_Pot_analog_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pot_analog_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pot_analog__PORT == 15 && ((Pot_analog__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pot_analog_Write(uint8 value);
void    Pot_analog_SetDriveMode(uint8 mode);
uint8   Pot_analog_ReadDataReg(void);
uint8   Pot_analog_Read(void);
void    Pot_analog_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pot_analog_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pot_analog_SetDriveMode() function.
     *  @{
     */
        #define Pot_analog_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pot_analog_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pot_analog_DM_RES_UP          PIN_DM_RES_UP
        #define Pot_analog_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pot_analog_DM_OD_LO           PIN_DM_OD_LO
        #define Pot_analog_DM_OD_HI           PIN_DM_OD_HI
        #define Pot_analog_DM_STRONG          PIN_DM_STRONG
        #define Pot_analog_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pot_analog_MASK               Pot_analog__MASK
#define Pot_analog_SHIFT              Pot_analog__SHIFT
#define Pot_analog_WIDTH              1u

/* Interrupt constants */
#if defined(Pot_analog__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pot_analog_SetInterruptMode() function.
     *  @{
     */
        #define Pot_analog_INTR_NONE      (uint16)(0x0000u)
        #define Pot_analog_INTR_RISING    (uint16)(0x0001u)
        #define Pot_analog_INTR_FALLING   (uint16)(0x0002u)
        #define Pot_analog_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pot_analog_INTR_MASK      (0x01u) 
#endif /* (Pot_analog__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pot_analog_PS                     (* (reg8 *) Pot_analog__PS)
/* Data Register */
#define Pot_analog_DR                     (* (reg8 *) Pot_analog__DR)
/* Port Number */
#define Pot_analog_PRT_NUM                (* (reg8 *) Pot_analog__PRT) 
/* Connect to Analog Globals */                                                  
#define Pot_analog_AG                     (* (reg8 *) Pot_analog__AG)                       
/* Analog MUX bux enable */
#define Pot_analog_AMUX                   (* (reg8 *) Pot_analog__AMUX) 
/* Bidirectional Enable */                                                        
#define Pot_analog_BIE                    (* (reg8 *) Pot_analog__BIE)
/* Bit-mask for Aliased Register Access */
#define Pot_analog_BIT_MASK               (* (reg8 *) Pot_analog__BIT_MASK)
/* Bypass Enable */
#define Pot_analog_BYP                    (* (reg8 *) Pot_analog__BYP)
/* Port wide control signals */                                                   
#define Pot_analog_CTL                    (* (reg8 *) Pot_analog__CTL)
/* Drive Modes */
#define Pot_analog_DM0                    (* (reg8 *) Pot_analog__DM0) 
#define Pot_analog_DM1                    (* (reg8 *) Pot_analog__DM1)
#define Pot_analog_DM2                    (* (reg8 *) Pot_analog__DM2) 
/* Input Buffer Disable Override */
#define Pot_analog_INP_DIS                (* (reg8 *) Pot_analog__INP_DIS)
/* LCD Common or Segment Drive */
#define Pot_analog_LCD_COM_SEG            (* (reg8 *) Pot_analog__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pot_analog_LCD_EN                 (* (reg8 *) Pot_analog__LCD_EN)
/* Slew Rate Control */
#define Pot_analog_SLW                    (* (reg8 *) Pot_analog__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pot_analog_PRTDSI__CAPS_SEL       (* (reg8 *) Pot_analog__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pot_analog_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pot_analog__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pot_analog_PRTDSI__OE_SEL0        (* (reg8 *) Pot_analog__PRTDSI__OE_SEL0) 
#define Pot_analog_PRTDSI__OE_SEL1        (* (reg8 *) Pot_analog__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pot_analog_PRTDSI__OUT_SEL0       (* (reg8 *) Pot_analog__PRTDSI__OUT_SEL0) 
#define Pot_analog_PRTDSI__OUT_SEL1       (* (reg8 *) Pot_analog__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pot_analog_PRTDSI__SYNC_OUT       (* (reg8 *) Pot_analog__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pot_analog__SIO_CFG)
    #define Pot_analog_SIO_HYST_EN        (* (reg8 *) Pot_analog__SIO_HYST_EN)
    #define Pot_analog_SIO_REG_HIFREQ     (* (reg8 *) Pot_analog__SIO_REG_HIFREQ)
    #define Pot_analog_SIO_CFG            (* (reg8 *) Pot_analog__SIO_CFG)
    #define Pot_analog_SIO_DIFF           (* (reg8 *) Pot_analog__SIO_DIFF)
#endif /* (Pot_analog__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pot_analog__INTSTAT)
    #define Pot_analog_INTSTAT            (* (reg8 *) Pot_analog__INTSTAT)
    #define Pot_analog_SNAP               (* (reg8 *) Pot_analog__SNAP)
    
	#define Pot_analog_0_INTTYPE_REG 		(* (reg8 *) Pot_analog__0__INTTYPE)
#endif /* (Pot_analog__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pot_analog_H */


/* [] END OF FILE */
