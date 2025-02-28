
/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"
#include "Rte_SpeedSensor.h"
#include <stdio.h>

extern FUNC(void, RTE_CODE) Rte_Call_ReadSpeed(VAR(void, AUTOMATIC))

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
    printf("Executing Sensor_Read_Task...\n");

    if (Rte_status != RTE_STATUS_RUN)
    {
        printf("Error: RTE not ready. Skipping speed read.\n");
        TerminateTask();
        return;
    }

    Std_ReturnType status = Rte_Call_ReadSpeed();

    if (status == RTE_E_OK)
    {
        printf("Speed reading successful.\n");
    }
    else
    {
        printf("Error: Speed reading failed with code %d\n", status);
    }

    TerminateTask();
}