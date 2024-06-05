/*
 * Filename: sc_breaklight_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Break Light signal class
 * name: sc_breakLight
 * shortname: breakLight
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_breaklight_type.h"



/* USER CODE START SC_BREAKLIGHT_INCLUDE */

/* USER CODE END SC_BREAKLIGHT_INCLUDE */




/* USER CODE START SC_BREAKLIGHT_USERDEFINITIONS */

/* USER CODE END SC_BREAKLIGHT_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_BREAKLIGHT signal  ****************
 *****************************************************************************************/
 
 
/**
 * Default OUT driver API
 */
inline RC_t SC_BREAKLIGHT_driverOut(const SC_BREAKLIGHT_data_t  *const data)
{
	/* USER CODE START driverOutSC_BREAKLIGHT */


    
   
	//Scale application data to drive format
    uint8_t ledState = 0;
    ledState = data->breakLightStatus;
	//Write scaled data to driver
    RC_t result =  LED_Set(LED_RED, ledState ); 
	return result;
	/* USER CODE END driverOutSC_BREAKLIGHT */
}



