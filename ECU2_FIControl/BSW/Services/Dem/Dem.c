#include "Dem.h"
#include <stdio.h>

static VAR(uint16_t, AUTOMATIC) StoredDTC = 0;

FUNC(void, DEM_CODE)
Dem_Init(void)
{
    StoredDTC = 0;
    // printf("Initializing DEM...\n");
    // printf("DEM Initialized.\n");
}

FUNC(Std_ReturnType, DEM_CODE) Dem_ReportFIValveError(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) dtc)
{
    StoredDTC = DEM_DTC_FI_VALVE_ERROR;
    *dtc = StoredDTC;
    // printf("DEM: FI Valve Error Reported, Assigned DTC: 0x%X\n", *dtc);
    return RTE_E_OK; // Mock setup, always succeeds
}