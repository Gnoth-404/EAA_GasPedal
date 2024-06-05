/**
* \file <filename>
* \author <author-name>
* \date <date>
*
* \brief <Symbolic File name>
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#include "watchdog.h"
#include "project.h"
#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/



/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
static int8_t WD_RunnableAliveBitField;

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/




/**
 * Activate the Watchdog trigger
 * \param WDT_Timeout_t - [IN] Timeout period
 * \return RC_SUCCESS
 */

RC_t WD_Start(WDT_Timeout_t timeout){
    CyWdtStart(timeout, CYWDT_LPMODE_NOCHANGE);
    return RC_SUCCESS;
}



/**
 * Service the Watchdog trigger
 
 * \return RC_SUCCESS
*/
RC_t WD_Trigger(){
    
    if(WD_RunnableAliveBitField == 0x0f) // 11111 5 runnables alive, TFT is on to do list, set 4 runnable atm
    {
        CyWdtClear();
        WD_RunnableAliveBitField = 0; // reset bit field
    }    
    return RC_SUCCESS;
}


/**
* This function sets the bit at the corresponding position ( 8 bit datatype) 
* Can monitor upto 8 alive runnables
* It is called by every runnable using a uniqe position.
* 0 = readJoystick, 1 = calcControl, 2 = setEngine, 3 = setBrakeLight , 4 = HMI
* @return RC_SUCCESS
*/


RC_t WD_Alive(uint8_t myBitPosition){
    
    WD_RunnableAliveBitField |= (1U) << myBitPosition;
    return RC_SUCCESS;
}


/**
 * Check the watchdog bit

 * \return TRUE if watchdog reset bit was set
 */

boolean_t WD_CheckResetBit(){
    if(CyResetStatus & CY_RESET_WD) // Check the Watchdog register to determine the cause of the reset
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

