
/*
 * Filename: sc_breaklight_type.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Break Light signal class
 */

#ifndef _H_DEFINE_SC_BREAKLIGHT_TYPE
#define _H_DEFINE_SC_BREAKLIGHT_TYPE

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SC_BREAKLIGHT_INCLUDES */

/* USER CODE END SC_BREAKLIGHT_INCLUDES */



/**********************************************************************
 *       Type Definition for SC_BREAKLIGHT signal    
 **********************************************************************/

/* USER CODE START SC_BREAKLIGHT_USERDEFINITIONS */

/* USER CODE END SC_BREAKLIGHT_USERDEFINITIONS */

typedef 
/* USER CODE START SC_BREAKLIGHT_SIGNALDATADEFINITION */
struct
{
	#error "Provide your data structure"
} 
/* USER CODE END SC_BREAKLIGHT_SIGNALDATADEFINITION */
SC_BREAKLIGHT_data_t;

/* USER CODE START InitSC_BREAKLIGHT */
#error "Provide a sensible init value"
#define SC_BREAKLIGHT_INIT_DATA ((SC_BREAKLIGHT_data_t){})
/* USER CODE END InitSC_BREAKLIGHT */




/**
 * Default OUT driver API
 * \param const SC_BREAKLIGHT_data_t  *const data : [IN] signal data for the driver, will be scaled in this function
 * \return RC_SUCCESS is all was ok, error code otherwise
 */
RC_t SC_BREAKLIGHT_driverOut(const SC_BREAKLIGHT_data_t  *const data);


/* USER CODE START SC_BREAKLIGHT_USERFUNCTIONS */

/* USER CODE END SC_BREAKLIGHT_USERFUNCTIONS */


#endif