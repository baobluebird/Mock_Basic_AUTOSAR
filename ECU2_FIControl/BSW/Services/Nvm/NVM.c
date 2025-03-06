#include "NVM.h"
#include "../../ECU_Abstraction/MemIf/MemIf.h"
#include <stdio.h>

static VAR(uint32, AUTOMATIC) BlockBaseAddress[NVM_BLOCK_ID_1 + 1] = {0, 0};

FUNC(void, NVM_CODE)
NvM_Init(void)
{
    printf("Initializing NvM...\n");
    BlockBaseAddress[NVM_BLOCK_ID_1] = 0;
    MemIf_Init();
    printf("NvM Initialized.\n");
}

FUNC(Std_ReturnType, NVM_CODE) NvM_Write(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    Std_ReturnType status;
    if (blockId != NVM_BLOCK_ID_1)
    {
        printf("NvM Write Failed: Invalid Block ID %d\n", blockId);
        return RTE_E_INVALID;
    }

    status = MemIf_Write(BlockBaseAddress[blockId], data, NVM_BLOCK_SIZE);
    if (status == RTE_E_OK)
    {
        printf("NvM Write Successful - Block ID: %d\n", blockId);
    }
    else
    {
        printf("NvM Write Failed - Block ID: %d\n", blockId);
    }
    return status;
}

FUNC(Std_ReturnType, NVM_CODE) NvM_Read(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    Std_ReturnType status;
    if (blockId != NVM_BLOCK_ID_1)
    {
        printf("NvM Read Failed: Invalid Block ID %d\n", blockId);
        return RTE_E_INVALID;
    }

    status = MemIf_Read(BlockBaseAddress[blockId], data, NVM_BLOCK_SIZE);
    if (status == RTE_E_OK)
    {
        printf("NvM Read Successful - Block ID: %d\n", blockId);
    }
    else
    {
        printf("NvM Read Failed - Block ID: %d\n", blockId);
    }
    return status;
}