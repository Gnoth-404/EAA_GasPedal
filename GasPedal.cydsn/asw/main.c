/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "global.h"

#include <stdlib.h>
#include <stdio.h>
#include "joystick.h"
#include "watchdog.h"
#include "button.h"
#include "led.h"
//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
   
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}
void hardware_init()
{
    
    CyGlobalIntDisable;
    
    JOYSTICK_Init();
    UART_LOG_Start();
    LED_Init();
    CyGlobalIntEnable;
}
/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    //Init MCAL Drivers

    
    hardware_init();
    WD_Start(TIMEOUT_2s);
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	UART_LOG_PutString("EAA Lab1 - Nguyen Tien Anh Ha\n");
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    
	if(WD_CheckResetBit())
    {
        UART_LOG_PutString("The system has been reset due to WatchDog Timer!!!\n");
    }
    else
    {
        UART_LOG_PutString("The system has been reset through Power on button!!!\n");
    }
    
    //Start the alarm with 5ms cycle time
    SetRelAlarm(alrm_Tick5ms,5,5);
    
    ActivateTask(tsk_io);
    ActivateTask(tsk_control);
    ActivateTask(tsk_tft);
    ActivateTask(tsk_system);
    ActivateTask(tsk_background);
    
    TerminateTask();
    
}





TASK(tsk_background)
{
    while(1)
    {
        //do something with low prioroty
        // feed our lovely watchdog if runnables are running
        WD_Trigger();
        
    }
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/


/* [] END OF FILE */
