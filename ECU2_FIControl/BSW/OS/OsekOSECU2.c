#include "os.h"

static uint8_t FIControl_Toggle = 0U;
static uint8_t CanRecevie_Toggle = 0U;
static uint8_t DemSend_Toggle = 0U;
static uint8_t NvmLogging_Toggle = 0U;

volatile uint8_t SensorTask_Running = 0;
volatile uint8_t CanTask_Running = 0;
volatile uint8_t DEMTask_Running = 0;
volatile uint8_t NVMLoggingTask_Running = 0;

volatile uint8_t Check_Data_Read = 0;
volatile uint8_t Check_Data_Send = 0;
volatile uint8_t Check_Dem_Send = 0;
volatile uint8_t Check_Nvm_Stored = 0;


void SystemInit(void) {}

int main(void)
{
	  
    StartOS();
    while (1);
    return 0;
}

TASK(CAN_Receive_Task)
{		
	  //SensorTask_Running = 1; //check time task Can_Send_Task
		CanRecevie_Toggle ^= 1;
	  ActivateTask(FIControl_Task);
		SetEvent(FIControl_Task, SpeedReceiveEvt);
	 // SensorTask_Running = 0;//check time task Sensor_Read_Task
	
	  TerminateTask(); 
	  
}

TASK(FIControl_Task)
{
    //CanTask_Running = 1;//check time task Can_Send_Task
	
    WaitEvent(SpeedReceiveEvt); 
    ClearEvent(SpeedReceiveEvt); 
	
		FIControl_Toggle ^= 1; 
	

	  //CanTask_Running = 0;//check time task Can_Send_Task
	
	  TerminateTask(); 
	
}

TASK(DEM_Task)
{
    //DEMTask_Running = 1;//check time task DEM_Task
	
    WaitEvent(DemReqEvt); 
    ClearEvent(DemReqEvt); 
    DemSend_Toggle ^= 1; 

	  TerminateTask(); 
	
}

TASK(NVM_Logging_Task)
{
    //NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task
	
    WaitEvent(NvmReqEvt); 
    ClearEvent(NvmReqEvt); 
    NvmLogging_Toggle ^= 1; 

	
	  //NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task
	
	  TerminateTask(); 
	
}
