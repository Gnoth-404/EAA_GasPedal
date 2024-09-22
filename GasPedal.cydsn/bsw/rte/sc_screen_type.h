
/*
 * Filename: sc_screen_type.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Signal for displaying on screen
 */

#ifndef _H_DEFINE_SC_SCREEN_TYPE
#define _H_DEFINE_SC_SCREEN_TYPE

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SC_SCREEN_INCLUDES */

/* USER CODE END SC_SCREEN_INCLUDES */



/**********************************************************************
 *       Type Definition for SC_SCREEN signal    
 **********************************************************************/

/* USER CODE START SC_SCREEN_USERDEFINITIONS */
#include "tft.h"
/* USER CODE END SC_SCREEN_USERDEFINITIONS */

typedef 
/* USER CODE START SC_SCREEN_SIGNALDATADEFINITION */
struct
{
	uint8_t dummy_screen;
} 
/* USER CODE END SC_SCREEN_SIGNALDATADEFINITION */
SC_SCREEN_data_t;

/* USER CODE START InitSC_SCREEN */

#define SC_SCREEN_INIT_DATA ((SC_SCREEN_data_t){0})
/* USER CODE END InitSC_SCREEN */




/**
 * Default OUT driver API
 * \param const SC_SCREEN_data_t  *const data : [IN] signal data for the driver, will be scaled in this function
 * \return RC_SUCCESS is all was ok, error code otherwise
 */
RC_t SC_SCREEN_driverOut(const SC_SCREEN_data_t  *const data);


/* USER CODE START SC_SCREEN_USERFUNCTIONS */

/* USER CODE END SC_SCREEN_USERFUNCTIONS */


#endif