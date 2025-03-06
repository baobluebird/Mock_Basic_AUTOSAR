#ifndef RTE_FICONTROL_H
#define RTE_FICONTROL_H

#include "../Common/Compiler.h"
#include "../RTE/Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FIValve_State(
    VAR(uint8, AUTOMATIC) state
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FIValve_State(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state
);

#endif /* RTE_FICONTROL_H */