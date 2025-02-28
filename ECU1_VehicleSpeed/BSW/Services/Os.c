/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"
#include "RTE/Rte_SpeedSensor.h"
#include "RTE/Rte_Can.h"
#include <stdio.h>

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(VAR(float*, AUTOMATIC));
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CANMessage(VAR(float, AUTOMATIC));

static volatile VAR(float, AUTOMATIC) SharedSpeedData = 0.0F;
static volatile VAR(Std_ReturnType, AUTOMATIC) SharedSpeedStatus = RTE_E_NOT_OK;

DeclareTask(Sensor_Read_Task);
DeclareTask(Can_Send_Task);

void SystemInit(void) {}

int main(void)
{
    StartOS();
    while (1)
        ; /* Should not be executed */
    return 0;
}

TASK(Sensor_Read_Task)
{
    VAR(float, AUTOMATIC) speed = 0.0F;
    VAR(Std_ReturnType, AUTOMATIC) status;

    printf("Executing Sensor_Read_Task...\n");

    status = Rte_Call_RP_SpeedSensorSWC_ReadSpeed(&speed);
    if (status == RTE_E_OK)
    {
        printf("Speed Data Read: %.2f m/s\n", speed);

        SharedSpeedData = speed;
        SharedSpeedStatus = RTE_E_OK;

        SetEvent(Can_Send_Task, SpeedReady_Event);
    }
    else
    {
        printf("Error: Failed to read speed data!\n");
        SharedSpeedStatus = RTE_E_NOT_OK;
    }

    TerminateTask();
}


TASK(Can_Send_Task)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    VAR(EventMaskType, AUTOMATIC) events;

    printf("Executing Can_Send_Task...\n");

    WaitEvent(SpeedReady_Event);
    GetEvent(Can_Send_Task, &events);
    ClearEvent(SpeedReady_Event);

    if (SharedSpeedStatus == RTE_E_OK)
    {
        status = Rte_Write_CANMessage(SharedSpeedData);
        if (status == RTE_E_OK)
        {
            printf("Speed Data Sent via CAN: %.2f m/s\n", SharedSpeedData);
        }
        else
        {
            printf("Error: Failed to send speed data via CAN!\n");
        }
    }
    else
    {
        printf("Error: No valid speed data available! (SharedSpeedStatus = %d)\n", SharedSpeedStatus);
    }

    TerminateTask();
}

