#include "Rte_NVBlock.h"
#include "BSW/Services/Nvm/NVM.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    return NvM_WriteBlock(blockId, data);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NVBlock_Data(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    return NvM_ReadBlock(blockId, data);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvmInterface_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC)
{
    return NvM_WriteDTC(DTC);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvmInterface_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC)
{
    return NvM_ReadDTC(DTC);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvmInterface_ClearDTC(void)
{
    return NvM_ClearDTC();
}