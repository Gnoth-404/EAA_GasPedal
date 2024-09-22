
/*
 * Filename: swc_clock.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Electronic Clock SWC
 */

#ifndef _H_DEFINE_SWC_CLOCK
#define _H_DEFINE_SWC_CLOCK

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_CLOCK_INCLUDES */

#include "sp_common.h"

/* USER CODE END SWC_CLOCK_INCLUDES */



/* USER CODE START SWC_CLOCK_USERDEFINITIONS */

/* USER CODE END SWC_CLOCK_USERDEFINITIONS */


/*
 * component: swc_Clock
 * cycletime: 50
 * description: Runnable handle button timer 
 * events: 
 * name: CLOCK_input_run
 * shortname: input
 * signalIN: 
 * signalOUT: so_event
 * task: tsk_io
 */
void CLOCK_input_run(RTE_event ev);

/*
 * component: swc_Clock
 * cycletime: 100
 * description: Runnable control state machine
 * events: ev_event_onData
 * name: CLOCK_control_run
 * shortname: control
 * signalIN: so_event
 * signalOUT: 
 * task: tsk_control
 */
void CLOCK_control_run(RTE_event ev);

/*
 * component: swc_Clock
 * cycletime: 250
 * description: Runnable display on TFT
 * events: 
 * name: CLOCK_display_run
 * shortname: display
 * signalIN: so_clock
 * signalOUT: 
 * task: tsk_hmi
 */
void CLOCK_display_run(RTE_event ev);


#endif