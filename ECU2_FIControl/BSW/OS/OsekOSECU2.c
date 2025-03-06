#include "os.h"
#include "Rte_CalibPara.h"
#include "Rte_FIControl.h"

static uint8_t CalibPara_Toggle = 0U;
static uint8_t FIControl_Toggle = 0U;
static uint8_t InjectorControl_Toggle = 0U;
static uint8_t NvmLogging_Toggle = 0U;

volatile uint8_t FIControlTask_Running = 0;
volatile uint8_t CalibParaTask_Running = 0;
volatile uint8_t NVMLoggingTask_Running = 0;

volatile uint8_t Check_Param_Init = 0;
volatile uint8_t Check_Param_Read = 0;
volatile uint8_t Check_Read_Speed = 0;
volatile uint8_t Check_Speed_Over = 0;
volatile uint8_t Check_Control_Injector = 0;
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
	while (1)
		;
	return 0;
}

TASK(CalibPara_Task)
{
	// CalibParaTask_Running = 1;//check time task DEM_Task
	CalibPara_Toggle ^= 1;
	VAR(Std_ReturnType, AUTOMATIC)
	status;
	status = Rte_Call_CalibPara_InitThreshold();
	if (status == RTE_E_OK)
	{
		Check_Param_Init = 1;
		ActivateTask(FIControl_Task);
		SetRelAlarm(Alarm_Periodic, 100, 10);
	}
	else
	{
		Check_Param_Init = 0;
	}

	// CalibParaTask_Running = 0;//check time task DEM_Task
	TerminateTask();
}

TASK(FIControl_Task)
{
	// FIControlTask_Running = 1;//check time task FIControl_Task
	VAR(Std_ReturnType, AUTOMATIC)
	statusThreshold;
	statusThreshold = Rte_Call_FIControlSWC_ReadCalibData();

	FIControl_Toggle ^= 1;

	if (statusThreshold == RTE_E_OK)
	{
		Check_Param_Read = 1;
		VAR(Std_ReturnType, AUTOMATIC) statusReadSpeed;
		statusReadSpeed = Rte_Call_FIControlSWC_ReadCANData();
		if (statusReadSpeed == RTE_E_OK)
		{
			Check_Read_Speed = 1;
			ActivateTask(Injector_Control_Task);
			SetEvent(Injector_Control_Task, ControlEvt);
		}
		else
		{
			Check_Read_Speed = 0;
		}
	}
	else
	{
		Check_Param_Read = 0;
	}

	// FIControlTask_Running = 0;//check time task FIControl_Task

	TerminateTask();
}

TASK(Injector_Control_Task)
{
	// NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task

	WaitEvent(ControlEvt);
	ClearEvent(ControlEvt);
	InjectorControl_Toggle ^= 1;
	VAR(Std_ReturnType, AUTOMATIC) statusCompare;
	statusCompare = Rte_Call_FIControlSWC_CompareSpeedAndThreshold();
	if (statusCompare == RTE_E_OK)
	{
		Check_Speed_Over = 1;
		VAR(Std_ReturnType, AUTOMATIC) statusControl;
		statusControl = Rte_Call_FIControlSWC_ControlFIValve(1U); //turn on injector
		if (statusControl == RTE_E_OK)
		{
			Check_Control_Injector = 1;
		}
		else
		{
			Check_Control_Injector = 0;
		}
	}
	else
	{
		Check_Speed_Over = 0;
		VAR(Std_ReturnType, AUTOMATIC) statusControl;
		statusControl = Rte_Call_FIControlSWC_ControlFIValve(0U); //turn off injector
		if (statusControl == RTE_E_OK)
		{
			Check_Control_Injector = 0;
		}
		else
		{
			Check_Control_Injector = 1;
		}
	}

	// NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task

	TerminateTask();
}

TASK(NVM_Logging_Task)
{
	// NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task

	WaitEvent(NvmReqEvt);
	ClearEvent(NvmReqEvt);
	NvmLogging_Toggle ^= 1;

	// NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task

	TerminateTask();
}
