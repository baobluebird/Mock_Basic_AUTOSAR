#include "FIControlSWC.h"
#include "Rte_FIControl.h"
#include "../RTE/Rte_Can.h"
#include "Rte_CalibPara.h"
#include "../RTE/Rte_Dem.h"
#include "../RTE/Rte_Nvm.h"
#include "../BSW/Services/Dem/Dem.h"
#include <stdio.h>

VAR(uint16_t, AUTOMATIC) SpeedThreshold = 0.0f;
VAR(uint16_t, AUTOMATIC) VehicleSpeed = 0.0f;

static VAR(uint16_t, FICONTROL_CODE) detectedDTC = 0;

volatile uint16_t read_threshold_simulation = 0.0f;
volatile uint16_t read_speed_simulation = 0.0f;

FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ReadCalibData(void)
{
    Std_ReturnType status = Rte_Read_CalibPara_SpeedThreshold(&SpeedThreshold);
	  read_threshold_simulation = SpeedThreshold;
    if (status != RTE_E_OK)
    {
        SpeedThreshold = 0.0f; // Reset to default on failure
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ReadCANData(void)
{
    Std_ReturnType status = Rte_Read_CANMessage(&VehicleSpeed);
	  read_speed_simulation = VehicleSpeed;
    if (status != RTE_E_OK)
    {
        VehicleSpeed = 0.0f;
    }
    return status;
}

FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_CompareSpeedAndThreshold(void)
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

FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState)
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

/**
 * @brief Runnable: Check for errors and report errors to DEM
 */
FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_CheckAndReportError(void)
{
    detectedDTC = DTC_SPEED_OVER_THRESHOLD;

    VAR(Std_ReturnType, AUTOMATIC) statusDem = Rte_Call_Dem_ReportErrorStatus(detectedDTC, DEM_EVENT_STATUS_FAILED);

    if (statusDem == RTE_E_OK)
    {
        return RTE_E_OK;
    }

    return RTE_E_NOT_OK;
}

/**
 *@brief Runnable: Save errors to NVBlockSWC before storing in NVM
 */
FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_SendErrorToNVBlockSWC(void)
{
    VAR(Std_ReturnType, AUTOMATIC) statusNVBlock;

    statusNVBlock = Rte_Write_NVDATA_DTC(detectedDTC);
    
    if (statusNVBlock == RTE_E_OK)
    {
        return RTE_E_OK;
    }

    return RTE_E_NOT_OK;
}
