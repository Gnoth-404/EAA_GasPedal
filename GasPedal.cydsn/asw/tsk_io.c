/*
 * Filename: tsk_io.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Task reading and writing input and output 
 * events: ev_5ms|ev_breakpedal_onData|ev_speed_onData
 * mode: Cyclic and Event
 * name: tsk_io
 * shortname: io
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: ev_5ms
 * timertickperiod: 5
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "tsk_io.h"



/* USER CODE START TSK_IO_INCLUDE */

/* USER CODE END TSK_IO_INCLUDE */

#include "swc_gaspedal.h"



/* USER CODE START TSK_IO_USERDEFINITIONS */

/* USER CODE END TSK_IO_USERDEFINITIONS */

/*******************************************************************************
 * Runnable Tables from Activation Engine
 *******************************************************************************/

/* Cyclic Table */

const RTE_cyclicTable_t RTE_cyclicActivationTable_tsk_io[] = {
	{ GASPEDAL_readJoystick_run, 10 },	//Runnable that reads joystick data value x and y every 10ms and update joystick signal
	{ GASPEDAL_setEngine_run, 100 },	//Runnable that take the input speed signal value and write it to engine(Green LED)
};
const uint16_t RTE_cyclicActivation_tsk_io_size = sizeof (RTE_cyclicActivationTable_tsk_io) / sizeof(RTE_cyclicTable_t); 

/* Event Table */
const RTE_eventTable_t RTE_eventActivationTable_tsk_io[] = {
    { GASPEDAL_setBrakeLight_run, ev_speed_onData },  //Runnable
}; 
const uint16_t RTE_eventActivation_tsk_io_size = sizeof (RTE_eventActivationTable_tsk_io) / sizeof(RTE_eventTable_t);

/*******************************************************************************
 * Task Body
 *******************************************************************************/


/*
 * description: Task reading and writing input and output 
 * events: ev_5ms|ev_breakpedal_onData|ev_speed_onData
 * mode: Cyclic and Event
 * name: tsk_io
 * shortname: io
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: ev_5ms
 * timertickperiod: 5
 */
TASK(tsk_io)
{
	/* ticktime of the task */
	uint32_t ticktime = 0;
	
    EventMaskType ev = 0;
	
	/* USER CODE START TSK_IO_INIT */

	/* USER CODE END TSK_IO_INIT */
    
    while(1)
    {
        //Wait, read and clear the event
        WaitEvent(ev_5ms|ev_breakpedal_onData|ev_speed_onData);
        GetEvent(tsk_io,&ev);
        ClearEvent(ev);
    
		/* USER CODE START TSK_IO_TASKBOBY_PRE */

		/* USER CODE END TSK_IO_TASKBODY_PRE */
        
        if (ev & ev_5ms){
            //Process Cyclic table on tick
            RTE_ProcessCyclicTable(RTE_cyclicActivationTable_tsk_io, RTE_cyclicActivation_tsk_io_size, ticktime);

			ticktime += 5;
			if (ticktime > 0xFFFFFF00) ticktime = 0;

		};
		
		//Process data driven events
		RTE_ProcessEventTable(RTE_eventActivationTable_tsk_io, RTE_eventActivation_tsk_io_size, ev);
		
		/* USER CODE START TSK_IO_TASKBODY_POST */

		/* USER CODE END TSK_IO_TASKBODY_POST */
        
    }
	
	//Just in Case
	TerminateTask();
}


/*******************************************************************************
 * Interrupt Service Routines
 *******************************************************************************/

/* USER CODE START TSK_IO_ISR */
ISR2(isr_Button)
{
    if(BUTTON_IsPressed(BUTTON_1))
    {
        ShutdownOS(0);
    }
    else if(BUTTON_IsPressed(BUTTON_2))
    {
        SetEvent(tsk_control, ev_breakpedal_onData);
    }
}
/* USER CODE END TSK_IO_ISR */
