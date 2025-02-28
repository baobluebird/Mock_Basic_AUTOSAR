/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"
#include "RTE/Rte_SpeedSensor.h"
#include "RTE/Rte_Can.h"
#include <stdio.h>

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(VAR(float*, AUTOMATIC));
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CANMessage(VAR(float, AUTOMATIC));

DeclareTask(Sensor_Read_Task);
DeclareTask(Init_Task);

void SystemInit(void) {}

int main(void)
{
    StartOS();
    while (1)
        ; /* Should not be executed */
    return 0;
}

TASK(Init_Task)
{
    printf("Initializing System...\n");
    TerminateTask();
}

TASK(Sensor_Read_Task)
{
    VAR(float, AUTOMATIC) speed;
    VAR(Std_ReturnType, AUTOMATIC) status;

    printf("Executing Sensor_Read_Task...\n");

    status = Rte_Call_RP_SpeedSensorSWC_ReadSpeed(&speed);
    if (status == RTE_E_OK)
    {
        printf("Speed Data Read: %.2f m/s\n", speed);

        status = Rte_Write_CANMessage(speed);
        if (status == RTE_E_OK)
        {
            printf("Speed Data Sent via CAN: %.2f m/s\n", speed);
        }
        else
        {
            printf("Error: Failed to send speed data via CAN!\n");
        }
    }
    else
    {
        printf("Error: Failed to read speed data!\n");
    }

    TerminateTask();
}
