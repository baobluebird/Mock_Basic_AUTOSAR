#ifndef RTE_CALIBPARA_H
#define RTE_CALIBPARA_H

#include "Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CalibPara_InitThreshold(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalibPara_SpeedThreshold(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) threshold
);



#endif /* RTE_CALIBPARA_H */