#include "Rte_Dem.h"
#include "BSW/Services/Dem/Dem.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_ReportFIValveError(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) dtc)
{
    return Dem_ReportFIValveError(dtc);
}