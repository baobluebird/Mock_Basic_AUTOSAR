#include "FIControlSWC.h"
#include "FIControlSWC_cfg.h"
#include "../RTE/Rte_FIControl.h"
#include "../RTE/Rte_Can.h"
#include "../RTE/Rte_CalibPara.h"
#include <stdio.h>

VAR(uint16, AUTOMATIC) SpeedThreshold = 0.0f;
VAR(uint16, AUTOMATIC) VehicleSpeed = 0.0f;

FUNC(Std_ReturnType, FICONTROL_CODE)
FIControlSWC_Init(void)
{
    SpeedThreshold = 0.0f;
    VehicleSpeed = 0.0f;
    return RTE_E_OK;
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCalibData(void)
{
    Std_ReturnType status = Rte_Read_CalibPara_SpeedThreshold(&SpeedThreshold);
    if (status != RTE_E_OK)
    {
        SpeedThreshold = 0.0f; // Reset to default on failure
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCANData(void)
{
    Std_ReturnType status = Rte_Read_CANMessage(&VehicleSpeed);
    if (status != RTE_E_OK)
    {
        VehicleSpeed = 0.0f;
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ControlFIValve(void)
{
    uint8 valveState;
    Std_ReturnType status;

    if (VehicleSpeed > SpeedThreshold)
    {
        status = Rte_Write_FIValve_State(FICONTROL_VALVE_OFF);
        if (status != RTE_E_OK)
        {
            return status;
        }
    }
    else
    {
        status = Rte_Write_FIValve_State(FICONTROL_VALVE_ON);
        if (status != RTE_E_OK)
        {
            return status;
        }
    }
    status = Rte_Read_FIValve_State(&valveState);
    return status;
}
