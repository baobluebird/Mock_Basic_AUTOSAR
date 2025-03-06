#ifndef RTE_CALIBPARA_H
#define RTE_CALIBPARA_H

#include "../Common/Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalibPara_SpeedThreshold(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) threshold
);

#endif /* RTE_CALIBPARA_H */