#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "Dem.h"
#include "Compiler.h"
#include "Std_ReturnType.h"
/*-----------------------------------------------------------------------------------------*/
/* Function Prototypes */
/*-----------------------------------------------------------------------------------------*/

/**
 * @brief Report diagnostic error to DEM
 * @param DTC Diagnostic Trouble Code
 * @param status Error status (Passed, Failed, Pending, Confirmed)
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_ReportErrorStatus(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status);

/**
 * @brief Send error message to Speed ​​Sensor SWC for processing
 * @param DTC Diagnostic Trouble Code
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemInterface_ErrorConfirmed(VAR(uint16_t, AUTOMATIC) DTC);

/**
 * @brief Write DTC to non-volatile memory
 * @param DTC Diagnostic Trouble Code
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvmInterface_WriteDTC(VAR(uint16_t, AUTOMATIC) DTC);

#endif