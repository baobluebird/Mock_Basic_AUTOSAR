#ifndef CALIBPARA_SWC_H
#define CALIBPARA_SWC_H

#include "Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, CALIBPARA_CODE) CalibParaSWC_Init(void);

extern FUNC(Std_ReturnType, CALIBPARA_CODE) CalibParaSWC_GetSpeedThreshold(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) threshold
);

#endif /* CALIBPARA_SWC_H */