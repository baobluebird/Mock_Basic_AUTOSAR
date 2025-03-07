#include "NVBlockSWC.h"
#include "Rte_NVBlock.h"
#include <stdio.h>

static VAR(uint8, AUTOMATIC) NVData[NVM_BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78};

FUNC(Std_ReturnType, NVBLOCK_CODE)
NVBlockSWC_Init(void)
{
    printf("Initializing NVBlockSWC...\n");
    NvM_Init();
    printf("NVBlockSWC Initialized.\n");
    return RTE_E_OK;
}

FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_WriteBlock(void)
{
    Std_ReturnType status = Rte_Write_NVBlock_Data(NVM_BLOCK_ID_1, NVData);
    if (status == RTE_E_OK)
    {
        printf("NVBlockSWC: Write Block Success: %02X %02X %02X %02X\n",
               NVData[0], NVData[1], NVData[2], NVData[3]);
    }
    else
    {
        printf("NVBlockSWC: Write Block Failed\n");
    }
    return status;
}

FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ReadBlock(void)
{
    uint8 readData[NVM_BLOCK_SIZE] = {0};
    Std_ReturnType status = Rte_Read_NVBlock_Data(NVM_BLOCK_ID_1, readData);
    return status;
}

FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC)
{
    Std_ReturnType status = Rte_Write_NvmInterface_WriteDTC(DTC);
    return status;
}

FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC)
{
    Std_ReturnType status = Rte_Read_NvmInterface_ReadDTC(DTC);
    return status;
}

FUNC(Std_ReturnType, NVBLOCK_CODE) NVBlockSWC_ClearDTC(void)
{
    Std_ReturnType status = Rte_Call_NvmInterface_ClearDTC();
    return status;
}