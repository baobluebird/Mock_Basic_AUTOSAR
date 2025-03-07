#ifndef MEMIF_H
#define MEMIF_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

typedef enum {
    MEMIF_EEPROM,
    MEMIF_FLASH
} MemIf_MemoryType;

#define MEMIF_BLOCK_SIZE 64U

extern FUNC(void, MEMIF_CODE) MemIf_Init(void);

extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length
);

extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length
);

extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Erase(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    VAR(uint32, AUTOMATIC) length
);

#endif /* MEMIF_H */