
/*
 * Filename: sc_clock_type.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Storing clock data( hour + minute widget)
 */

#ifndef _H_DEFINE_SC_CLOCK_TYPE
#define _H_DEFINE_SC_CLOCK_TYPE

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SC_CLOCK_INCLUDES */
#include "statemachine.h"
#include "tft.h"
/* USER CODE END SC_CLOCK_INCLUDES */



/**********************************************************************
 *       Type Definition for SC_CLOCK signal    
 **********************************************************************/

/* USER CODE START SC_CLOCK_USERDEFINITIONS */
extern STATE_t CLOCK_StateMachine; // Clock container state machine global object
extern STATE_t CLOCK_WidgetStateMachine; // Widget container state machine global object
    
typedef enum{
    IS_DISPLAYING,
    IS_EDITING_HOUR,
    IS_EDITING_MIN,
    IS_EDITING,


    IS_AUTO_INCREMENTING,
}CLOCK_State_t;

typedef enum{
    CLOCK_WIDGET_NONE,
    CLOCK_WIDGET_HOUR,
    CLOCK_WIDGET_MIN,
}CLOCK_ActiveWidget_t;

typedef struct{
    uint8_t size;
    TFT_colors_t bg_color;
    TFT_colors_t widget_color;
    uint8_t x_pos;
    uint8_t y_pos;
} CLOCK_font_t;

typedef struct{
    STATE_t*  m_widgetStateMachine;
    uint8_t m_value;
    CLOCK_font_t font_type;
} CLOCK_Widget_t;



    
    
/* USER CODE END SC_CLOCK_USERDEFINITIONS */

typedef 
/* USER CODE START SC_CLOCK_SIGNALDATADEFINITION */
struct
{
	STATE_t* m_clockStateMachine; // Container
    CLOCK_ActiveWidget_t m_activeWidget;
    CLOCK_Widget_t m_hourWidget;
    CLOCK_Widget_t m_minWidget;
    
} 
/* USER CODE END SC_CLOCK_SIGNALDATADEFINITION */
SC_CLOCK_data_t;

/* USER CODE START InitSC_CLOCK */

#define SC_CLOCK_INIT_DATA ((SC_CLOCK_data_t){0,0, {0,0,{4,BLACK,WHITE,10,60}}, {0,0,{4,BLACK,WHITE,80,60}}})
/* USER CODE END InitSC_CLOCK */


/**
 * Default IN driver API
 * \param SC_CLOCK_data_t *const data : [OUT] scaled data read from the driver
 * \return RC_SUCCESS is all was ok, error code otherwise
 */
RC_t SC_CLOCK_driverIn(SC_CLOCK_data_t *const data);



/**
 * Default OUT driver API
 * \param const SC_CLOCK_data_t  *const data : [IN] signal data for the driver, will be scaled in this function
 * \return RC_SUCCESS is all was ok, error code otherwise
 */
RC_t SC_CLOCK_driverOut(const SC_CLOCK_data_t  *const data);


/* USER CODE START SC_CLOCK_USERFUNCTIONS */

/* USER CODE END SC_CLOCK_USERFUNCTIONS */


#endif