#include "os.h"

static uint8_t CalibPara_Toggle = 0U;
static uint8_t FIControl_Toggle = 0U;
static uint8_t InjectorControl_Toggle = 0U;
static uint8_t NvmLogging_Toggle = 0U;

volatile uint8_t FIControlTask_Running = 0;
volatile uint8_t CalibParaTask_Running = 0;
volatile uint8_t NVMLoggingTask_Running = 0;

volatile uint8_t Check_Param_Read = 0;
volatile uint8_t Check_Speed_Over = 0;
volatile uint8_t Check_Dem_Send = 0;
volatile uint8_t Check_Nvm_Stored = 0;

volatile uint16_t speed = 0;
volatile uint16_t speedThreshold = 0;

DeclareTask(CalibPara_Task);
DeclareTask(FIControl_Task);
DeclareTask(Injector_Control_Task);

void SystemInit(void) {}

int main(void)
{
	  
    StartOS();
    while (1);
    return 0;
}

TASK(CalibPara_Task)
{
    //CalibParaTask_Running = 1;//check time task DEM_Task
		CalibPara_Toggle ^= 1;
	  speedThreshold = 120;
		ActivateTask(FIControl_Task);

    SetRelAlarm(Alarm_Periodic, 100, 10);
		//CalibParaTask_Running = 0;//check time task DEM_Task
	  TerminateTask(); 
	
}

TASK(FIControl_Task)
{
    //FIControlTask_Running = 1;//check time task FIControl_Task
    uint16_t random_speed = (uint16_t)(rand() % 30 + 100);
    speed = random_speed;
    FIControl_Toggle ^= 1; 	
	  if(speed > speedThreshold)
		{
			  Check_Speed_Over = 1;
		  	ActivateTask(Injector_Control_Task);
				SetEvent(Injector_Control_Task, ControlEvt);
		}
		else
		{
			  Check_Speed_Over = 0;
		}

	  //FIControlTask_Running = 0;//check time task FIControl_Task
	
	  TerminateTask(); 
	
}

TASK(Injector_Control_Task)
{
    //NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task
	
    WaitEvent(ControlEvt); 
    ClearEvent(ControlEvt); 
    InjectorControl_Toggle ^= 1; 

	
	  //NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task
	
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
