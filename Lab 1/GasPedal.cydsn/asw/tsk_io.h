
/*
 * Filename: tsk_io.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Task reading and writing input and output 
 */

#ifndef _H_DEFINE_TSK_IO
#define _H_DEFINE_TSK_IO

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_IO_INCLUDES */

/* USER CODE END TSK_IO_INCLUDES */



/*
 * description: Task reading and writing input and output 
 * events: ev_10ms|ev_breakpedal_onData|ev_speed_onData
 * mode: Cyclic and Event
 * name: tsk_io
 * shortname: io
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: ev_10ms
 * timertickperiod: 1
 */
DeclareTask(tsk_io);

/* USER CODE START TSK_IO_TASKUSERFUNCTION */

/* USER CODE END TSK_IO_TASKUSERFUNCTION */


#endif