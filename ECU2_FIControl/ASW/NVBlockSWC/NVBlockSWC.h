#ifndef NVBLOCK_SWC_H
#define NVBLOCK_SWC_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

#define NVM_BLOCK_ID_1 1U
#define NVM_BLOCK_SIZE 4U

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_Init(void);

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_WriteBlock(void);

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ReadBlock(void);

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC
);

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC
);

extern FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ClearDTC(void);

#endif /* NVBLOCK_SWC_H */