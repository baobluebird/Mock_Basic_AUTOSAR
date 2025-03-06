#ifndef NVBLOCKSWC_H
#define NVBLOCKSWC_H

#include "Std_ReturnType.h"
#include "Compiler.h"

/* Runnable receives DTC from SpeedSensorSWC */
extern FUNC(Std_ReturnType, NVBLOCK_CODE) R_NVBlockSWC_ReceiveDTC(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) dtc);

/* Runnable saves DTCs to NVM */
extern FUNC(Std_ReturnType, NVBLOCK_CODE) R_NVBlockSWC_StoreDTCToNVM(void);

#endif /* NVBLOCKSWC_H */