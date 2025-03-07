#ifndef DEM_H
#define DEM_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

#define DEM_DTC_FI_VALVE_ERROR 0x1001U // Example DTC for FI valve error

extern FUNC(void, DEM_CODE) Dem_Init(void);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ReportFIValveError(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) dtc
);

#endif /* DEM_H */