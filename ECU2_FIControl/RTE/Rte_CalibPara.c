#include "Rte_CalibPara.h"
#include "CalibParaSWC.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CalibPara_InitThreshold(void)
{
    return CalibParaSWC_Init();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalibPara_SpeedThreshold(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) threshold)
{
    return CalibParaSWC_GetSpeedThreshold(threshold);
}