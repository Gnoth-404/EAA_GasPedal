
/*
 * Filename: tsk_output.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Task doing work
 */

#ifndef _H_DEFINE_TSK_OUTPUT
#define _H_DEFINE_TSK_OUTPUT

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_OUTPUT_INCLUDES */

/* USER CODE END TSK_OUTPUT_INCLUDES */



/*
 * description: Task doing work
 * events: ev_onUpdate
 * mode: Cyclic and Event
 * name: tsk_output
 * shortname: output
 * signalpoolsRO: 
 * signalpoolsRW: 
 * tickEvent: ev_onUpdate
 * timertickperiod: 1
 */
DeclareTask(tsk_output);

/* USER CODE START TSK_OUTPUT_TASKUSERFUNCTION */

/* USER CODE END TSK_OUTPUT_TASKUSERFUNCTION */


#endif