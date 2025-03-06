#include "Rte_NVBlock.h"
#include "../BSW/Services/Nvm/NVM.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    return NvM_Write(blockId, data);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    return NvM_Read(blockId, data);
}
