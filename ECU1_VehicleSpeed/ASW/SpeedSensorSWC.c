#include "SpeedSensorSWC.h"
#include "RTE/Rte_SpeedSensor.h"
#include "BSW/Services/Dem.h"
#include <stdio.h>

/*------------------------------------------------------------------------------*/
/* Static Variables */
/*------------------------------------------------------------------------------*/
static VAR(float, SPEEDSENSOR_VAR) vehicleSpeed ​​= 0.0;

/*------------------------------------------------------------------------------*/
/* Function Implementations */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes Speed ​​Sensor SWC
 */
FUNC(void, SPEEDSENSOR_CODE) SpeedSensorSWC_Init(VAR(void, AUTOMATIC))
{
    printf("Speed ​​Sensor SWC Initialized.\n");
}

/**
 * @brief Runnable: Read speed from sensor
 */
FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_ReadSpeed(VAR(void, AUTOMATIC))
{
    VAR(float, AUTOMATIC) speed;
    VAR(Std_ReturnType, AUTOMATIC) status = Rte_Read_ReceiveSpeed(&speed);

    if (status == RTE_E_OK)
    {
        vehicleSpeed ​​= speed;
        printf("Vehicle Speed: %.2f m/s\n", vehicleSpeed);

        if (vehicleSpeed ​​> 120.0)
        {
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_PASSED);
        }
    }
    else
    {
        printf("Error: Unable to read speed from sensor (Error Code: %d)\n", status);
    }

    return status;
}
