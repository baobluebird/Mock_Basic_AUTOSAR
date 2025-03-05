#include "os.h"
#include "Rte_SpeedSensor.h"
#include "Rte_Can.h"

static uint8_t SensorData_Toggle = 0U;
static uint8_t DemSend_Toggle = 0U;
static uint8_t NvmLogging_Toggle = 0U;

volatile uint8_t SensorTask_Running = 0;
volatile uint8_t DEMTask_Running = 0;
volatile uint8_t NVMLoggingTask_Running = 0;

volatile uint8_t Check_Data_Read = 0;
volatile uint8_t Check_Data_Send = 0;
volatile uint8_t Check_Dem_Send = 0;
volatile uint8_t Check_Nvm_Stored = 0;

VAR(uint16_t, AUTOMATIC) speed;

DeclareTask(Sensor_Read_Task);

DeclareTask(DEM_Task);
DeclareTask(NVM_Logging_Task);

void SystemInit(void) {}

int main(void)
{
	  
    StartOS();
    while (1);
    return 0;
}

TASK(Sensor_Read_Task)
{		
	  //SensorTask_Running = 1; //check time task Can_Send_Task
		SensorData_Toggle ^= 1;
	  VAR(Std_ReturnType, AUTOMATIC) status;
		status = Rte_Call_RP_SpeedSensorSWC_ReadSpeed(&speed);

		if (status == RTE_E_OK)
		{
				Check_Data_Read = 1;
			  status = Rte_Call_SpeedSensorSWC_SendSpeedToCAN();
				if (status == RTE_E_OK)
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
				status = Rte_Call_SpeedSensorSWC_CheckAndReportError();
	
				if (status == RTE_E_OK)
				{
						Check_Dem_Send = 1;
						ActivateTask(NVM_Logging_Task);
						SetEvent(NVM_Logging_Task, NvmReqEvt);

				}
				else
				{
						 Check_Dem_Send = 0;
				}
		}

	 // SensorTask_Running = 0;//check time task Sensor_Read_Task
	
	  TerminateTask(); 
	  
}


TASK(NVM_Logging_Task)
{
    //NVMLoggingTask_Running = 1;//check time task NVM_Logging_Task
	
    WaitEvent(NvmReqEvt); 
    ClearEvent(NvmReqEvt); 
    NvmLogging_Toggle ^= 1; 
	  VAR(Std_ReturnType, AUTOMATIC) status;
	  status = Rte_Call_SpeedSensorSWC_StoreErrorToNVM();
	
	
	  if (status == RTE_E_OK)
		{
				Check_Nvm_Stored = 1;

		}
		else
		{
			Check_Nvm_Stored = 0;
		}
	  //NVMLoggingTask_Running = 0;//check time task NVM_Logging_Task
	
	  TerminateTask(); 
	
}
