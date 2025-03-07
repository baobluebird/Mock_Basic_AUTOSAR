#ifndef NVM_H
#define NVM_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

#define NVM_BLOCK_ID_1 1U
#define NVM_BLOCK_SIZE 4U
#define NVM_DTC_ADDRESS 0x0001U
#define NVM_DTC_SIZE 2U

extern FUNC(void, NVM_CODE) NvM_Init(void);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ClearDTC(void);

#endif /* NVM_H */