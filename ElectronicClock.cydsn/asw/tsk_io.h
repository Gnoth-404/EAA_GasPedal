
/*
 * Filename: tsk_io.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Task handling button event
 */

#ifndef _H_DEFINE_TSK_IO
#define _H_DEFINE_TSK_IO

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_IO_INCLUDES */

/* USER CODE END TSK_IO_INCLUDES */



/*
 * description: Task handling button event
 * events: 
 * mode: Cyclic
 * name: tsk_io
 * shortname: io
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: 0
 * timertickperiod: 10
 */
DeclareTask(tsk_io);

/* USER CODE START TSK_IO_TASKUSERFUNCTION */

/* USER CODE END TSK_IO_TASKUSERFUNCTION */


#endif