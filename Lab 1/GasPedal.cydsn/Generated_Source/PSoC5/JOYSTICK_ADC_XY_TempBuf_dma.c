/***************************************************************************
* File Name: JOYSTICK_ADC_XY_TempBuf_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <JOYSTICK_ADC_XY_TempBuf_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* JOYSTICK_ADC_XY_TempBuf__DRQ_CTL_REG
* 
* 
* JOYSTICK_ADC_XY_TempBuf__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* JOYSTICK_ADC_XY_TempBuf__NUMBEROF_TDS
* 
* Priority of this channel.
* JOYSTICK_ADC_XY_TempBuf__PRIORITY
* 
* True if JOYSTICK_ADC_XY_TempBuf_TERMIN_SEL is used.
* JOYSTICK_ADC_XY_TempBuf__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* JOYSTICK_ADC_XY_TempBuf__TERMIN_SEL
* 
* 
* True if JOYSTICK_ADC_XY_TempBuf_TERMOUT0_SEL is used.
* JOYSTICK_ADC_XY_TempBuf__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* JOYSTICK_ADC_XY_TempBuf__TERMOUT0_SEL
* 
* 
* True if JOYSTICK_ADC_XY_TempBuf_TERMOUT1_SEL is used.
* JOYSTICK_ADC_XY_TempBuf__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* JOYSTICK_ADC_XY_TempBuf__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of JOYSTICK_ADC_XY_TempBuf dma channel */
uint8 JOYSTICK_ADC_XY_TempBuf_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 JOYSTICK_ADC_XY_TempBuf_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 JOYSTICK_ADC_XY_TempBuf_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    JOYSTICK_ADC_XY_TempBuf_DmaHandle = (uint8)JOYSTICK_ADC_XY_TempBuf__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(JOYSTICK_ADC_XY_TempBuf_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)JOYSTICK_ADC_XY_TempBuf__TERMOUT0_SEL,
                                  (uint8)JOYSTICK_ADC_XY_TempBuf__TERMOUT1_SEL,
                                  (uint8)JOYSTICK_ADC_XY_TempBuf__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(JOYSTICK_ADC_XY_TempBuf_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(JOYSTICK_ADC_XY_TempBuf_DmaHandle, (uint8)JOYSTICK_ADC_XY_TempBuf__PRIORITY);
    
    return JOYSTICK_ADC_XY_TempBuf_DmaHandle;
}

/*********************************************************************
* Function Name: void JOYSTICK_ADC_XY_TempBuf_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with JOYSTICK_ADC_XY_TempBuf.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void JOYSTICK_ADC_XY_TempBuf_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(JOYSTICK_ADC_XY_TempBuf_DmaHandle);
}

