#include "FIControlSWC.h"
#include "FIControlSWC_cfg.h"
#include "Rte_FIControl.h"
#include "Rte_Can.h"
#include "Rte_CalibPara.h"
#include <stdio.h>

FUNC(void, FICONTROL_CODE)
FIControlSWC_Init(void)
{
    printf("Initializing FIControlSWC...\n");
}

FUNC(void, FICONTROL_CODE) FIControlSWC_MainFunction(void)
{
    float threshold;
    float speed;
    uint8 valveState;
    Std_ReturnType status;

    status = Rte_Read_CalibPara_SpeedThreshold(&threshold);
    if (status != RTE_E_OK)
    {
        printf("FIControlSWC: Failed to read speed threshold\n");
        return;
    }

    status = Rte_Read_CANMessage(&speed);
    if (status != RTE_E_OK)
    {
        printf("FIControlSWC: Failed to read CAN speed\n");
        return;
    }

    if (speed > threshold)
    {
        Rte_Write_FIValve_State(FICONTROL_VALVE_OFF);
        printf("FIControlSWC: Speed %.2f > Threshold %.2f, Valve OFF\n", speed, threshold);
    }
    else
    {
        Rte_Write_FIValve_State(FICONTROL_VALVE_ON);
        printf("FIControlSWC: Speed %.2f <= Threshold %.2f, Valve ON\n", speed, threshold);
    }

    status = Rte_Read_FIValve_State(&valveState);
    if (status == RTE_E_OK)
    {
        printf("FIControlSWC: Current Valve State: %s\n", 
               (valveState == FICONTROL_VALVE_ON) ? "ON" : "OFF");
    }
}