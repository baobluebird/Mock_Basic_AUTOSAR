#include "SpeedSensorSWC.h"
#include "Rte_SpeedSensor.h"
#include "Rte_Can.h"
#include "Rte_Dem.h"
#include "Rte_Nvm.h"
#include "Dem.h"
#include <stdio.h>

/*------------------------------------------------------------------------------*/
/* Static Variables */
/*------------------------------------------------------------------------------*/
static VAR(uint16_t, SPEEDSENSOR_VAR) vehicleSpeed = 0.0F;
static VAR(uint16_t, SPEEDSENSOR_VAR) detectedDTC = 0;
/*------------------------------------------------------------------------------*/
/* Function Implementations */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes Speed ​​Sensor SWC
 */
FUNC(void, SPEEDSENSOR_CODE)
R_SpeedSensorSWC_Init(VAR(void, AUTOMATIC))
{
    printf("Speed ​​Sensor SWC Initialized.\n");
}

/**
 * @brief Runnable: Check for errors and report errors to DEM
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_CheckAndReportError(void)
{
    detectedDTC = DTC_SPEED_SENSOR_FAILURE;

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
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_SendErrorToNVBlockSWC(void)
{
    VAR(Std_ReturnType, AUTOMATIC) statusNVBlock;

    statusNVBlock = Rte_Write_NVDATA_DTC(detectedDTC);
    
    if (statusNVBlock == RTE_E_OK)
    {
        return RTE_E_OK;
    }

    return RTE_E_NOT_OK;
}


/**
 * @brief Runnable: Send speed data to CAN
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_SendSpeedToCAN(void)
{
    VAR(Std_ReturnType, AUTOMATIC) statusCAN;

    if(vehicleSpeed == 0)
    {
        return RTE_E_NOT_OK;
    }

    statusCAN = Rte_Write_CANMessage(vehicleSpeed);

    if (statusCAN == RTE_E_OK)
    {
        return RTE_E_OK;
    }
    return RTE_E_NOT_OK;
}

/**
 * @brief Runnable: Read speed from sensor
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_ReadSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (speed == NULL_PTR)
    {
        return RTE_E_INVALID;
    }

    VAR(Std_ReturnType, AUTOMATIC) statusRead = Rte_Read_ReceiveSpeed(speed);

    if (statusRead == RTE_E_OK)
    {
        vehicleSpeed = *speed;
    }

    return statusRead;
}

