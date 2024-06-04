/*
 * Filename: tsk_init.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Initialization driver
 * events: 
 * mode: Event
 * name: tsk_init
 * shortname: init
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: 0
 * timertickperiod: 1
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "tsk_init.h"



/* USER CODE START TSK_INIT_INCLUDE */

/* USER CODE END TSK_INIT_INCLUDE */




/* USER CODE START TSK_INIT_USERDEFINITIONS */

/* USER CODE END TSK_INIT_USERDEFINITIONS */

/*******************************************************************************
 * Runnable Tables from Activation Engine
 *******************************************************************************/

/* Event Table */
const RTE_eventTable_t RTE_eventActivationTable_tsk_init[] = {
}; 
const uint16_t RTE_eventActivation_tsk_init_size = sizeof (RTE_eventActivationTable_tsk_init) / sizeof(RTE_eventTable_t);

/*******************************************************************************
 * Task Body
 *******************************************************************************/


/*
 * description: Initialization driver
 * events: 
 * mode: Event
 * name: tsk_init
 * shortname: init
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: 0
 * timertickperiod: 1
 */
TASK(tsk_init)
{
    EventMaskType ev = 0;
    
	/* USER CODE START TSK_INIT_INIT */

	/* USER CODE END TSK_INIT_INIT */
	
    while(1)
    {
        //Wait, read and clear the event
        WaitEvent();
        GetEvent(tsk_init,&ev);
        ClearEvent(ev);
		
		/* USER CODE START TSK_INIT_TASKBOBY_PRE */

		/* USER CODE END TSK_INIT_TASKBODY_PRE */
    

        //Process Event table on event
        RTE_ProcessEventTable(RTE_eventActivationTable_tsk_init, RTE_eventActivation_tsk_init_size, ev);
		
		/* USER CODE START TSK_INIT_TASKBODY_POST */

		/* USER CODE END TSK_INIT_TASKBODY_POST */

        
    }
	
	//Just in Case
	TerminateTask();
}


/*******************************************************************************
 * Interrupt Service Routines
 *******************************************************************************/

/* USER CODE START TSK_INIT_ISR */

/* USER CODE END TSK_INIT_ISR */
