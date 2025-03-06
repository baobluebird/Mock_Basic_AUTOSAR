#include "FIControlSWC.h"
#include "Rte_FIControl.h"
#include "Rte_Can.h"
#include "Rte_CalibPara.h"
#include <stdio.h>

VAR(uint16_t, AUTOMATIC) SpeedThreshold = 0.0f;
VAR(uint16_t, AUTOMATIC) VehicleSpeed = 0.0f;

volatile uint16_t read_threshold_simulation = 0.0f;
volatile uint16_t read_speed_simulation = 0.0f;

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCalibData(void)
{
    Std_ReturnType status = Rte_Read_CalibPara_SpeedThreshold(&SpeedThreshold);
	  read_threshold_simulation = SpeedThreshold;
    if (status != RTE_E_OK)
    {
        SpeedThreshold = 0.0f; // Reset to default on failure
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCANData(void)
{
    Std_ReturnType status = Rte_Read_CANMessage(&VehicleSpeed);
	  read_speed_simulation = VehicleSpeed;
    if (status != RTE_E_OK)
    {
        VehicleSpeed = 0.0f;
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_CompareSpeedAndThreshold(void)
{
    if (VehicleSpeed > SpeedThreshold)
    {
        return RTE_E_OK;
    }
    else
    {
        return RTE_E_NOT_OK;
    }
}

FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState)
{
    uint8 valveState;
    Std_ReturnType status;

    if (controlState == FICONTROL_VALVE_ON)
    {
        status = Rte_Write_FIValve_State(FICONTROL_VALVE_ON);
        if (status != RTE_E_OK)
        {
            return status;
        }
    }
    else
    {
        status = Rte_Write_FIValve_State(FICONTROL_VALVE_OFF);
        if (status != RTE_E_OK)
        {
            return status;
        }
    }
    status = Rte_Read_FIValve_State(&valveState);
    return status;
}