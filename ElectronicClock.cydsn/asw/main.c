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
#include "tsk_system.h"
#include "tsk_control.h"
#include "led.h"
#include "logging.h"
#include "tft.h"
#include "sc_clock_type.h"
#include "sc_clock.h"
#include "sp_common.h"
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
    
    
    UART_LOG_Start();
    LED_Init();
    TFT_init();
    
    TFT_clearScreen();
    TFT_setTextSize(1);
    
    TFT_printf("   Electronic Clock   ");
    CyGlobalIntEnable;
}
/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    //Init MCAL Drivers

    
    hardware_init();
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    

        //Initialize the CLOCK state machine

    STATE_initState(&CLOCK_StateMachine);

    

    //Initialize the clock signal

    SC_CLOCK_data_t data = SC_CLOCK_INIT_DATA;

    

    data.m_clockStateMachine = &CLOCK_StateMachine;
    data.m_hourWidget.m_widgetStateMachine =    &CLOCK_WidgetStateMachine;
    data.m_minWidget.m_widgetStateMachine =     &CLOCK_WidgetStateMachine;

    RTE_SC_CLOCK_set(&SO_CLOCK_signal,data);

    SetRelAlarm(alrm_1ms,10,10);
    SetRelAlarm(alrm_hmi, 20, 15);
    ActivateTask(tsk_control);
    

    ActivateTask(tsk_background);
    
    TerminateTask();
    
    

    
}

void cb_1ms()

{   

    ActivateTask(tsk_system);

    ActivateTask(tsk_io);

    ActivateTask(tsk_hmi);

}





TASK(tsk_background)
{
    while(1)
    {

        
        __asm("nop");


        
    }
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/


/* [] END OF FILE */
