#ifndef FLASH_H
#define FLASH_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

#define FLASH_BLOCK_SIZE 64U
#define FLASH_TOTAL_SIZE 256U

extern FUNC(void, FLASH_CODE) FlashDrv_Init(void);

extern FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Write(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length
);

extern FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length
);

#endif /* FLASH_H */