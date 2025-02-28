#include "Rte_Dem.h"
#include "ASW/SpeedSensorSWC.h"

/*-------------------------------------------------------------------------*/
/* Function Implementations */
/*-------------------------------------------------------------------------------*/

/**
 * @brief Report diagnostic errors to DEM
 */
FUNC(void, RTE_CODE) Rte_Dem_ReportError(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status)
{
    if (DTC == 0)
    {
        printf("Error: Invalid DTC value (0x%X)\n", DTC);
        return;
    }

    Dem_ReportErrorStatus(DTC, status);

    printf("DEM Error Reported: DTC=0x%X, Status=%d\n", DTC, status);
}

/**
 * @brief Send error message to Speed ​​Sensor SWC for processing
 */
FUNC(void, RTE_CODE) Rte_Dem_NotifySpeedSensorSWC(VAR(uint16, AUTOMATIC) DTC)
{
    if (DTC == 0)
    {
        printf("Error: Invalid DTC value (0x%X) sent to SpeedSensorSWC\n", DTC);
        return;
    }

    SpeedSensorSWC_HandleError(DTC);

    printf("SpeedSensorSWC Notified with DTC=0x%X\n", DTC);
}