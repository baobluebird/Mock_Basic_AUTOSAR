#include "Rte_Call.h"
#include "../ASW/FIControlSWC/FIControlSWC.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_Init(void)
{
    return FIControlSWC_Init();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCalibData(void)
{
    return FIControlSWC_ReadCalibData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCANData(void)
{
    return FIControlSWC_ReadCANData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ControlFIValve(void)
{
    return FIControlSWC_ControlFIValve();
}