/*******************************************************************************
* File Name: Joystick_vertical.h  
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

#if !defined(CY_PINS_Joystick_vertical_H) /* Pins Joystick_vertical_H */
#define CY_PINS_Joystick_vertical_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Joystick_vertical_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Joystick_vertical__PORT == 15 && ((Joystick_vertical__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Joystick_vertical_Write(uint8 value);
void    Joystick_vertical_SetDriveMode(uint8 mode);
uint8   Joystick_vertical_ReadDataReg(void);
uint8   Joystick_vertical_Read(void);
void    Joystick_vertical_SetInterruptMode(uint16 position, uint16 mode);
uint8   Joystick_vertical_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Joystick_vertical_SetDriveMode() function.
     *  @{
     */
        #define Joystick_vertical_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Joystick_vertical_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Joystick_vertical_DM_RES_UP          PIN_DM_RES_UP
        #define Joystick_vertical_DM_RES_DWN         PIN_DM_RES_DWN
        #define Joystick_vertical_DM_OD_LO           PIN_DM_OD_LO
        #define Joystick_vertical_DM_OD_HI           PIN_DM_OD_HI
        #define Joystick_vertical_DM_STRONG          PIN_DM_STRONG
        #define Joystick_vertical_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Joystick_vertical_MASK               Joystick_vertical__MASK
#define Joystick_vertical_SHIFT              Joystick_vertical__SHIFT
#define Joystick_vertical_WIDTH              1u

/* Interrupt constants */
#if defined(Joystick_vertical__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Joystick_vertical_SetInterruptMode() function.
     *  @{
     */
        #define Joystick_vertical_INTR_NONE      (uint16)(0x0000u)
        #define Joystick_vertical_INTR_RISING    (uint16)(0x0001u)
        #define Joystick_vertical_INTR_FALLING   (uint16)(0x0002u)
        #define Joystick_vertical_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Joystick_vertical_INTR_MASK      (0x01u) 
#endif /* (Joystick_vertical__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Joystick_vertical_PS                     (* (reg8 *) Joystick_vertical__PS)
/* Data Register */
#define Joystick_vertical_DR                     (* (reg8 *) Joystick_vertical__DR)
/* Port Number */
#define Joystick_vertical_PRT_NUM                (* (reg8 *) Joystick_vertical__PRT) 
/* Connect to Analog Globals */                                                  
#define Joystick_vertical_AG                     (* (reg8 *) Joystick_vertical__AG)                       
/* Analog MUX bux enable */
#define Joystick_vertical_AMUX                   (* (reg8 *) Joystick_vertical__AMUX) 
/* Bidirectional Enable */                                                        
#define Joystick_vertical_BIE                    (* (reg8 *) Joystick_vertical__BIE)
/* Bit-mask for Aliased Register Access */
#define Joystick_vertical_BIT_MASK               (* (reg8 *) Joystick_vertical__BIT_MASK)
/* Bypass Enable */
#define Joystick_vertical_BYP                    (* (reg8 *) Joystick_vertical__BYP)
/* Port wide control signals */                                                   
#define Joystick_vertical_CTL                    (* (reg8 *) Joystick_vertical__CTL)
/* Drive Modes */
#define Joystick_vertical_DM0                    (* (reg8 *) Joystick_vertical__DM0) 
#define Joystick_vertical_DM1                    (* (reg8 *) Joystick_vertical__DM1)
#define Joystick_vertical_DM2                    (* (reg8 *) Joystick_vertical__DM2) 
/* Input Buffer Disable Override */
#define Joystick_vertical_INP_DIS                (* (reg8 *) Joystick_vertical__INP_DIS)
/* LCD Common or Segment Drive */
#define Joystick_vertical_LCD_COM_SEG            (* (reg8 *) Joystick_vertical__LCD_COM_SEG)
/* Enable Segment LCD */
#define Joystick_vertical_LCD_EN                 (* (reg8 *) Joystick_vertical__LCD_EN)
/* Slew Rate Control */
#define Joystick_vertical_SLW                    (* (reg8 *) Joystick_vertical__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Joystick_vertical_PRTDSI__CAPS_SEL       (* (reg8 *) Joystick_vertical__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Joystick_vertical_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Joystick_vertical__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Joystick_vertical_PRTDSI__OE_SEL0        (* (reg8 *) Joystick_vertical__PRTDSI__OE_SEL0) 
#define Joystick_vertical_PRTDSI__OE_SEL1        (* (reg8 *) Joystick_vertical__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Joystick_vertical_PRTDSI__OUT_SEL0       (* (reg8 *) Joystick_vertical__PRTDSI__OUT_SEL0) 
#define Joystick_vertical_PRTDSI__OUT_SEL1       (* (reg8 *) Joystick_vertical__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Joystick_vertical_PRTDSI__SYNC_OUT       (* (reg8 *) Joystick_vertical__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Joystick_vertical__SIO_CFG)
    #define Joystick_vertical_SIO_HYST_EN        (* (reg8 *) Joystick_vertical__SIO_HYST_EN)
    #define Joystick_vertical_SIO_REG_HIFREQ     (* (reg8 *) Joystick_vertical__SIO_REG_HIFREQ)
    #define Joystick_vertical_SIO_CFG            (* (reg8 *) Joystick_vertical__SIO_CFG)
    #define Joystick_vertical_SIO_DIFF           (* (reg8 *) Joystick_vertical__SIO_DIFF)
#endif /* (Joystick_vertical__SIO_CFG) */

/* Interrupt Registers */
#if defined(Joystick_vertical__INTSTAT)
    #define Joystick_vertical_INTSTAT            (* (reg8 *) Joystick_vertical__INTSTAT)
    #define Joystick_vertical_SNAP               (* (reg8 *) Joystick_vertical__SNAP)
    
	#define Joystick_vertical_0_INTTYPE_REG 		(* (reg8 *) Joystick_vertical__0__INTTYPE)
#endif /* (Joystick_vertical__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Joystick_vertical_H */


/* [] END OF FILE */
