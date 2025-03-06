#ifndef RTE_NVBLOCK_H
#define RTE_NVBLOCK_H

#include "../Common/Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

#endif /* RTE_NVBLOCK_H */