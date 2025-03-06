#ifndef RTE_FICONTROLSWC_H
#define RTE_FICONTROLSWC_H

#include "../Common/Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_Init(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCalibData(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ReadCANData(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FIControlSWC_ControlFIValve(void);

#endif /* RTE_FICONTROLSWC_H */