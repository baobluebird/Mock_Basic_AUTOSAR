#ifndef RTE_NVBLOCK_H
#define RTE_NVBLOCK_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvmInterface_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvmInterface_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC
);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvmInterface_ClearDTC(void);

#endif /* RTE_NVBLOCK_H */