#include "SpeedSensorSWC.h"
#include "Rte_SpeedSensor.h"
#include "Rte_Dem.h"
#include "Dem.h"
#include <stdio.h>

/*------------------------------------------------------------------------------*/
/* Static Variables */
/*------------------------------------------------------------------------------*/
static VAR(uint16_t, SPEEDSENSOR_VAR) vehicleSpeed = 0.0F;
static VAR(uint16_t, SPEEDSENSOR_VAR) detectedDTC = 0;
static VAR(uint8_t, SPEEDSENSOR_VAR) isErrorConfirmed = 0;
/*------------------------------------------------------------------------------*/
/* Function Implementations */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes Speed ​​Sensor SWC
 */
FUNC(void, SPEEDSENSOR_CODE)
SpeedSensorSWC_Init(VAR(void, AUTOMATIC))
{
    printf("Speed ​​Sensor SWC Initialized.\n");
}

/**
 * @brief Runnable: Check for errors and report errors to DEM
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE)
SpeedSensorSWC_CheckAndReportError(void)
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
 *@brief Runnable: Save errors to NVM if error has been acknowledged by DEM
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) SpeedSensorSWC_StoreErrorToNVM(void)
{
    
    VAR(Std_ReturnType, AUTOMATIC) statusNVM = Rte_Call_NvmInterface_WriteDTC(detectedDTC);
    
    return statusNVM;
    
}

/**
 * @brief Runnable: Read speed from sensor
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE)
R_ReadSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    if (speed == NULL_PTR)
    {
        return RTE_E_INVALID;
    }

    VAR(Std_ReturnType, AUTOMATIC)
    statusRead = Rte_Read_ReceiveSpeed(speed);

    // if (statusRead != RTE_E_OK)
    // {
    //     VAR(Std_ReturnType, AUTOMATIC) statusDem = Rte_Call_DemInterface_ErrorConfirmed(DTC_SPEED_SENSOR_FAILURE);

    //     if(statusDem == RTE_E_OK)
    //     {
    //         VAR(Std_ReturnType, AUTOMATIC) statusNVM = Rte_Call_NvmInterface_WriteDTC(DTC_SPEED_SENSOR_FAILURE);

    //         if (statusNVM == RTE_E_OK)
    //         {
    //             //printf("SpeedSensorSWC: DTC %X logged into NVM successfully\n", DTC_SPEED_SENSOR_FAILURE);
    //         }
    //         else
    //         {
    //             //printf("SpeedSensorSWC: Failed to log DTC %X into NVM\n", DTC_SPEED_SENSOR_FAILURE);
    //         }
    //     }
    //     else
    //     {
    //        // printf("SpeedSensorSWC: DEM did not confirm DTC %X\n", DTC_SPEED_SENSOR_FAILURE);
    //     }

    //     return statusRead;
    // }

    return statusRead;
}
