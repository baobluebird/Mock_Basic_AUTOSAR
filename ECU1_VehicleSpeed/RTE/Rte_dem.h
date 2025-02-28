#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "BSW/Services/Dem.h"

/*-----------------------------------------------------------------------------------------*/
/* Function Prototypes */
/*-----------------------------------------------------------------------------------------*/

/**
 * @brief Report diagnostic error to DEM
 * @param DTC Diagnostic Trouble Code
 * @param status Error status (Passed, Failed, Pending, Confirmed)
 */
extern FUNC(void, RTE_CODE) Rte_Dem_ReportError(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status);

/**
 * @brief Send error message to Speed ​​Sensor SWC for processing
 * @param DTC Diagnostic Trouble Code
 */
extern FUNC(void, RTE_CODE) Rte_Dem_NotifySpeedSensorSWC(VAR(uint16, AUTOMATIC) DTC);

#endif