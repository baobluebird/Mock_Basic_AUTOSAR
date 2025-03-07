#ifndef RTE_FICONTROL_H
#define RTE_FICONTROL_H

#include "Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FIValve_State(
    VAR(uint8, AUTOMATIC) state
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FIValve_State(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCalibData(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCANData(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_CompareSpeedAndThreshold(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState);

/** @brief RTE Call for OS to call Runnable SpeedSensorSWC_CheckAndReportError */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_CheckAndReportError(void);

/** @brief RTE Call for OS to call Runnable SpeedSensorSWC_StoreErrorToNVM */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_SendErrorToNVBlockSWC(void);

#endif /* RTE_FICONTROL_H */