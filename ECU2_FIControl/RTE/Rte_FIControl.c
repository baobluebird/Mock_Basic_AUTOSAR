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
    return R_FIControlSWC_ReadCalibData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCANData(void)
{
    return R_FIControlSWC_ReadCANData();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_CompareSpeedAndThreshold(void)
{
    return R_FIControlSWC_CompareSpeedAndThreshold();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState)
{
    return R_FIControlSWC_ControlFIValve(controlState);
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_CheckAndReportError */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_CheckAndReportError(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    status = R_FIControlSWC_CheckAndReportError();
    return status;
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_StoreErrorToNVM */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_SendErrorToNVBlockSWC(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    status = R_FIControlSWC_SendErrorToNVBlockSWC();
    return status;
}

