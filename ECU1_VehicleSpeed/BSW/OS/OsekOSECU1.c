#include "os.h"
#include "Rte_SpeedSensor.h"
#include "Rte_Can.h"
#include "Rte_Wdg.h"

static uint8_t SensorData_Toggle = 0U;
static uint8_t WatchdogMonitor_Toggle = 0U;
static uint8_t NvmLogging_Toggle = 0U;

volatile uint8_t SensorTask_Running = 0;
volatile uint8_t NVMLoggingTask_Running = 0;

volatile uint8_t Check_Data_Read = 0;
volatile uint8_t Check_Data_Send = 0;
volatile uint8_t Check_Dem_Send = 0;
volatile uint8_t Check_Send_DTC = 0;
volatile uint8_t Check_Nvm_Stored = 0;

volatile uint8_t Simulate_Error = 0;

VAR(uint16_t, AUTOMATIC) g_speed;

DeclareTask(Sensor_Read_Task);
DeclareTask(NVM_Logging_Task);

void SystemInit(void) {}

int main(void)
{
	StartOS();
	while (1)
		;
	return 0;
}

TASK(Sensor_Read_Task)
{
	SensorTask_Running = 1; //check time task Can_Send_Task
	SensorData_Toggle ^= 1;
	VAR(Std_ReturnType, AUTOMATIC) status;
	status = Rte_Call_RP_SpeedSensorSWC_ReadSpeed(&g_speed);

	if (status == RTE_E_OK)
	{
		Check_Data_Read = 1;
		VAR(Std_ReturnType, AUTOMATIC) statusSendSpeed;
		statusSendSpeed = Rte_Call_SpeedSensorSWC_SendSpeedToCAN();

		if (OsCnt_GetSystemCounter() == 1000)
		{
			Simulate_Error = 1;
		}
		if (Simulate_Error == 1)
		{
			// printf("Sensor Task Failed! System will reset...\n");
			while (1)
				;
		}

		if (statusSendSpeed == RTE_E_OK)
		{
			Check_Data_Send = 1;
		}
		else
		{
			Check_Data_Send = 0;
		}
	}
	else
	{
		Check_Data_Read = 0;
		VAR(Std_ReturnType, AUTOMATIC) statusCheckDem;
		statusCheckDem = Rte_Call_SpeedSensorSWC_CheckAndReportError();

		if (statusCheckDem == RTE_E_OK)
		{
			Check_Dem_Send = 1;
			VAR(Std_ReturnType, AUTOMATIC) statusSendDTC;
			statusSendDTC = Rte_Call_SpeedSensorSWC_SendErrorToNVBlockSWC();
			if (statusSendDTC == RTE_E_OK)
			{
				Check_Send_DTC = 1;
				ActivateTask(NVM_Logging_Task);
				SetEvent(NVM_Logging_Task, NvmReqEvt);
			}
			else
			{
				Check_Send_DTC = 0;
			}
		}
		else
		{
			Check_Dem_Send = 0;
		}
	}

	//check time task Sensor_Read_Task

	TerminateTask();
}

TASK(NVM_Logging_Task)
{
	SensorTask_Running = 0;
	NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task

	WaitEvent(NvmReqEvt);
	ClearEvent(NvmReqEvt);
	NvmLogging_Toggle ^= 1;
	VAR(Std_ReturnType, AUTOMATIC) status;
	status = Rte_Call_NVBlockSWC_StoreDTCToNVM();

	if (status == RTE_E_OK)
	{
		Check_Nvm_Stored = 1;
	}
	else
	{
		Check_Nvm_Stored = 0;
	}
	NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task

	TerminateTask();
}
