/*
 * Filename: tsk_control.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Controlling Electronic Clock State machine
 * events: ev_event_onData
 * mode: Event
 * name: tsk_control
 * shortname: control
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: ev_event_onData
 * timertickperiod: 0
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "tsk_control.h"



/* USER CODE START TSK_CONTROL_INCLUDE */

/* USER CODE END TSK_CONTROL_INCLUDE */

#include "swc_clock.h"



/* USER CODE START TSK_CONTROL_USERDEFINITIONS */

/* USER CODE END TSK_CONTROL_USERDEFINITIONS */

/*******************************************************************************
 * Runnable Tables from Activation Engine
 *******************************************************************************/

/* Event Table */
const RTE_eventTable_t RTE_eventActivationTable_tsk_control[] = {
    { CLOCK_control_run, ev_event_onData },  //Runnable control state machine
}; 
const uint16_t RTE_eventActivation_tsk_control_size = sizeof (RTE_eventActivationTable_tsk_control) / sizeof(RTE_eventTable_t);

/*******************************************************************************
 * Task Body
 *******************************************************************************/


/*
 * description: Controlling Electronic Clock State machine
 * events: ev_event_onData
 * mode: Event
 * name: tsk_control
 * shortname: control
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: ev_event_onData
 * timertickperiod: 0
 */
TASK(tsk_control)
{
    EventMaskType ev = 0;
    
	/* USER CODE START TSK_CONTROL_INIT */

	/* USER CODE END TSK_CONTROL_INIT */
	
    while(1)
    {
        //Wait, read and clear the event
        WaitEvent(ev_event_onData);
        GetEvent(tsk_control,&ev);
        ClearEvent(ev);
		
		/* USER CODE START TSK_CONTROL_TASKBOBY_PRE */

		/* USER CODE END TSK_CONTROL_TASKBODY_PRE */
    

        //Process Event table on event
        RTE_ProcessEventTable(RTE_eventActivationTable_tsk_control, RTE_eventActivation_tsk_control_size, ev);
		
		/* USER CODE START TSK_CONTROL_TASKBODY_POST */

		/* USER CODE END TSK_CONTROL_TASKBODY_POST */

        
    }
	
	//Just in Case
	TerminateTask();
}


/*******************************************************************************
 * Interrupt Service Routines
 *******************************************************************************/

/* USER CODE START TSK_CONTROL_ISR */

/* USER CODE END TSK_CONTROL_ISR */

