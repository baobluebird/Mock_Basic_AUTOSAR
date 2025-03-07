#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_ReportFIValveError(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) dtc
);

#endif /* RTE_DEM_H */