/*******************************************************************************
* File Name: Joystick_button.h  
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

#if !defined(CY_PINS_Joystick_button_H) /* Pins Joystick_button_H */
#define CY_PINS_Joystick_button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Joystick_button_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Joystick_button__PORT == 15 && ((Joystick_button__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Joystick_button_Write(uint8 value);
void    Joystick_button_SetDriveMode(uint8 mode);
uint8   Joystick_button_ReadDataReg(void);
uint8   Joystick_button_Read(void);
void    Joystick_button_SetInterruptMode(uint16 position, uint16 mode);
uint8   Joystick_button_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Joystick_button_SetDriveMode() function.
     *  @{
     */
        #define Joystick_button_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Joystick_button_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Joystick_button_DM_RES_UP          PIN_DM_RES_UP
        #define Joystick_button_DM_RES_DWN         PIN_DM_RES_DWN
        #define Joystick_button_DM_OD_LO           PIN_DM_OD_LO
        #define Joystick_button_DM_OD_HI           PIN_DM_OD_HI
        #define Joystick_button_DM_STRONG          PIN_DM_STRONG
        #define Joystick_button_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Joystick_button_MASK               Joystick_button__MASK
#define Joystick_button_SHIFT              Joystick_button__SHIFT
#define Joystick_button_WIDTH              1u

/* Interrupt constants */
#if defined(Joystick_button__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Joystick_button_SetInterruptMode() function.
     *  @{
     */
        #define Joystick_button_INTR_NONE      (uint16)(0x0000u)
        #define Joystick_button_INTR_RISING    (uint16)(0x0001u)
        #define Joystick_button_INTR_FALLING   (uint16)(0x0002u)
        #define Joystick_button_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Joystick_button_INTR_MASK      (0x01u) 
#endif /* (Joystick_button__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Joystick_button_PS                     (* (reg8 *) Joystick_button__PS)
/* Data Register */
#define Joystick_button_DR                     (* (reg8 *) Joystick_button__DR)
/* Port Number */
#define Joystick_button_PRT_NUM                (* (reg8 *) Joystick_button__PRT) 
/* Connect to Analog Globals */                                                  
#define Joystick_button_AG                     (* (reg8 *) Joystick_button__AG)                       
/* Analog MUX bux enable */
#define Joystick_button_AMUX                   (* (reg8 *) Joystick_button__AMUX) 
/* Bidirectional Enable */                                                        
#define Joystick_button_BIE                    (* (reg8 *) Joystick_button__BIE)
/* Bit-mask for Aliased Register Access */
#define Joystick_button_BIT_MASK               (* (reg8 *) Joystick_button__BIT_MASK)
/* Bypass Enable */
#define Joystick_button_BYP                    (* (reg8 *) Joystick_button__BYP)
/* Port wide control signals */                                                   
#define Joystick_button_CTL                    (* (reg8 *) Joystick_button__CTL)
/* Drive Modes */
#define Joystick_button_DM0                    (* (reg8 *) Joystick_button__DM0) 
#define Joystick_button_DM1                    (* (reg8 *) Joystick_button__DM1)
#define Joystick_button_DM2                    (* (reg8 *) Joystick_button__DM2) 
/* Input Buffer Disable Override */
#define Joystick_button_INP_DIS                (* (reg8 *) Joystick_button__INP_DIS)
/* LCD Common or Segment Drive */
#define Joystick_button_LCD_COM_SEG            (* (reg8 *) Joystick_button__LCD_COM_SEG)
/* Enable Segment LCD */
#define Joystick_button_LCD_EN                 (* (reg8 *) Joystick_button__LCD_EN)
/* Slew Rate Control */
#define Joystick_button_SLW                    (* (reg8 *) Joystick_button__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Joystick_button_PRTDSI__CAPS_SEL       (* (reg8 *) Joystick_button__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Joystick_button_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Joystick_button__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Joystick_button_PRTDSI__OE_SEL0        (* (reg8 *) Joystick_button__PRTDSI__OE_SEL0) 
#define Joystick_button_PRTDSI__OE_SEL1        (* (reg8 *) Joystick_button__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Joystick_button_PRTDSI__OUT_SEL0       (* (reg8 *) Joystick_button__PRTDSI__OUT_SEL0) 
#define Joystick_button_PRTDSI__OUT_SEL1       (* (reg8 *) Joystick_button__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Joystick_button_PRTDSI__SYNC_OUT       (* (reg8 *) Joystick_button__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Joystick_button__SIO_CFG)
    #define Joystick_button_SIO_HYST_EN        (* (reg8 *) Joystick_button__SIO_HYST_EN)
    #define Joystick_button_SIO_REG_HIFREQ     (* (reg8 *) Joystick_button__SIO_REG_HIFREQ)
    #define Joystick_button_SIO_CFG            (* (reg8 *) Joystick_button__SIO_CFG)
    #define Joystick_button_SIO_DIFF           (* (reg8 *) Joystick_button__SIO_DIFF)
#endif /* (Joystick_button__SIO_CFG) */

/* Interrupt Registers */
#if defined(Joystick_button__INTSTAT)
    #define Joystick_button_INTSTAT            (* (reg8 *) Joystick_button__INTSTAT)
    #define Joystick_button_SNAP               (* (reg8 *) Joystick_button__SNAP)
    
	#define Joystick_button_0_INTTYPE_REG 		(* (reg8 *) Joystick_button__0__INTTYPE)
#endif /* (Joystick_button__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Joystick_button_H */


/* [] END OF FILE */
