#ifndef DEM_ECU2_H
#define DEM_ECU2_H

#include <stdint.h>
#include <stdbool.h>
#include "Std_ReturnType.h"
#include "Compiler.h"
/* AUTOSAR Standard Event Status */
typedef enum {
    DEM_EVENT_STATUS_PASSED,     
    DEM_EVENT_STATUS_FAILED,     
    DEM_EVENT_STATUS_CONFIRMED   
} Dem_EventStatusType;

/* DTC ID */
#define DTC_NVM_WRITE_ERROR       0x9101
#define DTC_SPEED_OVER_THRESHOLD  0x1122
#define DTC_CAN_RECEIVE_ERROR        0x1234

extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus(VAR(uint16_t, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(VAR(uint16_t, AUTOMATIC) DTC, P2VAR(Dem_EventStatusType, AUTOMATIC, DEM_APPL_DATA) Status);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearDTC(VAR(uint16_t, AUTOMATIC) DTC);
extern FUNC(void, DEM_CODE) Dem_GetStoredDTC(P2VAR(uint16_t, AUTOMATIC, DEM_APPL_DATA) dtcList, P2VAR(uint8_t, AUTOMATIC, DEM_APPL_DATA) dtcCount);

#endif /* DEM_H */
