/*
 * Filename: sc_screen_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Signal for displaying on screen
 * name: sc_screen
 * shortname: screen
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_screen_type.h"



/* USER CODE START SC_SCREEN_INCLUDE */

/* USER CODE END SC_SCREEN_INCLUDE */




/* USER CODE START SC_SCREEN_USERDEFINITIONS */

/* USER CODE END SC_SCREEN_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_SCREEN signal  ****************
 *****************************************************************************************/
 
 
/**
 * Default OUT driver API
 */
inline RC_t SC_SCREEN_driverOut(const SC_SCREEN_data_t  *const data)
{
	/* USER CODE START driverOutSC_SCREEN */


	//Scale application data to drive format
    uint8_t dummy = data->dummy_screen;
    TFT_print("Further task");
    
	//Write scaled data to driver

	return RC_SUCCESS;
	/* USER CODE END driverOutSC_SCREEN */
}



