#include "Rte_CalibPara.h"
#include "../ASW/CalibParaSWC/CalibParaSWC.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalibPara_SpeedThreshold(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) threshold)
{
    return CalibParaSWC_GetSpeedThreshold(threshold);
}