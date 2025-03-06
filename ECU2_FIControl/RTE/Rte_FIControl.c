#include "Rte_FIControl.h"
#include "FIControlSWC.h"
#include "FI_ValveCDD.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FIValve_State(
    VAR(uint8, AUTOMATIC) state)
{
    return FI_ValveCDD_SetState(state);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FIValve_State(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state)
{
    return FI_ValveCDD_GetState(state);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCalibData(void)
{
    return FIControlSWC_ReadCalibData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCANData(void)
{
    return FIControlSWC_ReadCANData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_CompareSpeedAndThreshold(void)
{
    return FIControlSWC_CompareSpeedAndThreshold();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState)
{
    return FIControlSWC_ControlFIValve(controlState);
}