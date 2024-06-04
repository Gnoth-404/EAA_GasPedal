

/**
 *  file    SC_ENGINE_signal.h
 *
 *  brief   signal base class for signal sc_engine
 *
 *  author  Autogenerated, Peter Fromm       <peter.fromm@h-da.de>
 *
 * description: Engine signal class
 * name: sc_engine
 * shortname: engine
 *
 */



#ifndef SC_ENGINE_SIGNAL_H_INCLUDED
#define SC_ENGINE_SIGNAL_H_INCLUDED

/*================================================[ public includes  ]================================================*/
#include "global.h"
#include "project.h"
#include "rte.h"
#include "rte_types.h"

#include "sc_engine_type.h"


/********************************************************************************************************************/
/* The driver API block																						*/
/********************************************************************************************************************/
                                                                                                                       
/**
 *  Definition of function types for driver interfaces.
 *  I-Port
 */
typedef RC_t (*SC_ENGINE_driverIn_t)(SC_ENGINE_data_t * const);

/**
 *  Definition of function types for driver interfaces.
 *  O-Port
 */
typedef RC_t (*SC_ENGINE_driverOut_t)( const SC_ENGINE_data_t * const);


/********************************************************************************************************************/
/* The signal configuration API block																				*/
/********************************************************************************************************************/

/**
 * Instances of the struct SC_ENGINE_cfg_t represent the signal object configuration.
 */
struct SC_ENGINE_cfg_s
{
    /**
     * Function pointer to the input driver
     */
    SC_ENGINE_driverIn_t const inDriver;

    /**
     * Function pointer to the output driver table
     */
   SC_ENGINE_driverOut_t const outDriver;
   
    /**
     * Event onUpdate
     */
    EventMaskType const evOnUpdate;
    
    
    /**
     * Event onError
     */
    EventMaskType const evOnError;
    
    /**
     * Task Count onUpdate
     */
    size_t const onUpdateTaskCount;

    /**
     * Task List onUpdate
     */
    TaskTypeArray* const onUpdateTasks;
    
    /**
     * Task Count onError
     */
    size_t const onErrorTaskCount;

    /**
     * Task List onError
     */
    TaskTypeArray* const onErrorTasks;
	
	
	/**
	 * Ressourse is active? We need an additional boolean as a ressource value 0 is valid.
	 */
	 boolean_t const resourceActive;
	 
	/**
	 * Ressourse 
	 */
	 ResourceType const resource;

};                                                                                                                     
typedef const struct SC_ENGINE_cfg_s SC_ENGINE_cfg_t;
                              
/********************************************************************************************************************/
/* The data interface block																							*/
/********************************************************************************************************************/

                                                                                                                       
							  
/**
 * Instances of the struct SC_ENGINE_t represent the signal objects.
 * A signal object contains the current application value 'value' as well as relevant meta data.
 */
struct SC_ENGINE_s
{                                                                                                                      

	/**
	 * Data buffer for the application value
	 */
    SC_ENGINE_data_t value;

    /**
     * Current signal status
     */
    RTE_signalStatus_t status;

    /**
     * Current age of the signal (in calling cycles)
     */
    uint32_t age;

    /**
     * Pointer to the signal configuration
     */
	const SC_ENGINE_cfg_t * const    pSigCfg;

};                                                                                                                     
typedef struct SC_ENGINE_s SC_ENGINE_t;

/********************************************************************************************************************/
/* Signal initialisation   																							*/
/********************************************************************************************************************/

/**
 * Initializes a signal instance with a passed init value.
 * Depending on the configured conversion or scaling function the raw_value will be calculated.
 * Signal status will change from RTE_SIGNALSTATUS_STARTUP to RTE_SIGNALSTATUS_INITIALIZED.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object which will be initialised
 * @return RC_t: standard return code, currently only RC_SUCCESS
 *
 **/
inline RC_t RTE_SC_ENGINE_init( SC_ENGINE_t * const signal )
{                                                                                                                      

   RC_t ret = RC_SUCCESS;

   //Set value and raw value
   signal->value  = SC_ENGINE_INIT_DATA;
   signal->age    = 0;
   signal->status = RTE_SIGNALSTATUS_INITIALIZED;

   return ret;
}

/********************************************************************************************************************/
/* Status and timeout control																						*/
/********************************************************************************************************************/

/**
 *  Returns the current signal status of the passed signal instance.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @return  sig_status_t: The current signal status
 *
 **/
inline RTE_signalStatus_t RTE_SC_ENGINE_getStatus( const SC_ENGINE_t * const signal )
{
   return signal->status;
}


/**
 *  Sets a new signal status of the passed signal instance by passing the new status.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @param  const sig_status_t status: New signal status
 * @return RC_t: standard return code, currently only RC_SUCCESS
 *
 */
inline RC_t RTE_SC_ENGINE_setStatus( SC_ENGINE_t * const signal, const RTE_signalStatus_t status )
{
   signal->status = status;
   size_t taskNum=0;
   
   //Fire error events in case of invalid state
   if (signal->status == RTE_SIGNALSTATUS_INVALID)
   {
	    //Pointer to the Taskarray, containing the tasks receiving the onUpdate events
		TaskTypeArray* pTaskArray = signal->pSigCfg->onErrorTasks;

		if (0 != signal->pSigCfg->evOnError && NULL != pTaskArray){
			for( taskNum=0 ; taskNum < signal->pSigCfg->onErrorTaskCount ;taskNum++){
				TaskType task = (*pTaskArray)[taskNum];
				SetEvent( task, signal->pSigCfg->evOnError);
			}
		}
   }
   
   return RC_SUCCESS;
}


/**
 * Returns the count of refreshing trials (refresh, set or set_raw) that failed.
 * Prerquisite: The signal is refreshed cyclically
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @return uint32_t: Number of cycles since the signal has been updated for the last time
 */
inline uint32_t RTE_SC_ENGINE_getAge( const SC_ENGINE_t * const signal )
{
   return signal->age;
}

/**
 * Should be called by application or driver if no new value can be provided.
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @param uint32_t increment: incrementvalue, typically in [ms]
 * @return void
 */
inline void RTE_SC_ENGINE_incAge(  SC_ENGINE_t * const signal , uint32_t increment)
{
	   //Hack....
	   if ( 0xFFFF0000 > (signal->age + increment) )
	   {
	      signal->age += increment;
	   }
}


/********************************************************************************************************************/
/* Application Data read/write Interface																			*/
/********************************************************************************************************************/

/**
 * Returns the current application value as pointer to the signal payload.
 * Careful: This is not threadsafe!!!
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @return sc_engine_data_t*: pointer to the current value of the application data buffer
 *
 **/
inline SC_ENGINE_data_t* RTE_SC_ENGINE_getPtr( SC_ENGINE_t * const signal )
{               
   //Todo: Critical region cannot be protected using return values																						
   return &(signal->value);                                                                                               
}

/**
 * Returns the current application value of the passed signal instance.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @return sc_engine_data_t: current value of the application data buffer
 *
 **/
inline SC_ENGINE_data_t RTE_SC_ENGINE_get( const SC_ENGINE_t * const signal )
{               
   //Todo: Critical region cannot be protected using return values																						
   return signal->value;                                                                                               
}                                                                                                                      
                                                                                                                       
/**
 * Returns the current application value of the passed signal instance threadsafe.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @param  SC_ENGINE_data_t* data: Pointer to the return data Pointer to the signal object
 * @return RC_SUCCESS
 *
 **/
inline RC_t RTE_SC_ENGINE_getThreadSafe( const SC_ENGINE_t * const signal, SC_ENGINE_data_t * const data )
{    
   if (TRUE == signal->pSigCfg->resourceActive) GetResource(signal->pSigCfg->resource);
   *data = signal->value;
   if (TRUE == signal->pSigCfg->resourceActive) ReleaseResource(signal->pSigCfg->resource);          

   return RC_SUCCESS;                                                                   
   
}                                                                                                            
                                                                                                                       
/**
 * Sets a new application value to the passed signal instance by passing the new value.
 * The corresponding driver raw value will be calculated immediately by using the default conversion or calling the
 * signal specific scaling function.
 * The signal age will be set to 0 and the new status will be 'RTE_SIGNALSTATUS_VALID'.
 *
 * @param  SC_ENGINE_t * const signal: Pointer to the signal object
 * @param  sc_engine_data_t const value: value for the application data buffer
 * @return RC_t: standard return code, currently only RC_SUCCESS
 *
 **/
inline RC_t RTE_SC_ENGINE_set(SC_ENGINE_t * const signal, const SC_ENGINE_data_t value  )
{

   RC_t ret = RC_SUCCESS;
   size_t taskNum=0;


   if (TRUE == signal->pSigCfg->resourceActive) GetResource(signal->pSigCfg->resource);
   signal->value  = value;
   signal->age    = 0;
   signal->status = RTE_SIGNALSTATUS_VALID;
   if (TRUE == signal->pSigCfg->resourceActive) ReleaseResource(signal->pSigCfg->resource);

   //Pointer to the Taskarray, containing the tasks receiving the onUpdate events
   TaskTypeArray* pTaskArray = signal->pSigCfg->onUpdateTasks;

   if (0 != signal->pSigCfg->evOnUpdate && NULL != pTaskArray){
      for( taskNum=0 ; taskNum < signal->pSigCfg->onUpdateTaskCount ;taskNum++){
		  
          TaskType task = (*pTaskArray)[taskNum];
	      SetEvent( task, signal->pSigCfg->evOnUpdate);
      }
   }

   return ret;
}                                                                                                                      
                                                                                                                       
                                                                                                                      
/********************************************************************************************************************/
/* Call functions to the connected drivers																			*/
/********************************************************************************************************************/

                                                                                                                       
/**
 *  Calls the connected driver interface to get a new value.
 *
 * @param SC_ENGINE_t * const signal: Pointer to the signal object
 * @return  RC_t: Return value of the driver call
 *
 */
inline RC_t RTE_SC_ENGINE_pullPort( SC_ENGINE_t * const signal )
{                                                                                                                      
   RC_t ret = RC_SUCCESS;

                                                                                                                       
   if ( NULL != signal->pSigCfg->inDriver )
   {
	  SC_ENGINE_data_t value = signal->value;
      ret = signal->pSigCfg->inDriver(&value);
                                                                                                                       
      if ( ret == RC_SUCCESS )                                                                                         
      {
    	  //Critical Section
    	  RTE_SC_ENGINE_set(signal, value);
      }
      else
      {
		  //Signal is invalid. Error event (if present) will be fired
		  RTE_SC_ENGINE_setStatus(signal, RTE_SIGNALSTATUS_INVALID);
      }

   }                                                                                                                   
                                                                                                                       
   return ret;                                                                                                         
}                                                                                                                      
                                                                                                                       
/**
 *  Calls the connected driver interfaces to send a value. Value will not be sent if it is INVALID.
 *
 * @param SC_ENGINE_t * const signal: Pointer to the signal object
 * @return  RC_t: Return value of the driver call
 *
 **/
inline RC_t RTE_SC_ENGINE_pushPort( const SC_ENGINE_t * const signal )
{                                                                                                                      
   RC_t ret = RC_ERROR;

   if (RTE_SIGNALSTATUS_VALID == signal->status)
   {
	   ret = signal->pSigCfg->outDriver(&(signal->value));
   }
	
   //In case of an out-driver, no error event is thrown in case of an error code from the driver
   //Application has the responsibility to handle this
   
   return ret;                                                                                                         
}                                                                                                                      

#endif /* include guard */


