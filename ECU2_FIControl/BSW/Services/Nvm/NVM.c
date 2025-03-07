#include "Nvm.h"
#include "MemIf.h"
#include <stdio.h>

static VAR(uint32, AUTOMATIC) BlockBaseAddress[NVM_BLOCK_ID_1 + 1] = {0, 0};
static VAR(uint16, AUTOMATIC) NVM_STORAGE_DTC = 0;

FUNC(void, NVM_CODE)
NvM_Init(void)
{
    // printf("Initializing NvM...\n");
    BlockBaseAddress[NVM_BLOCK_ID_1] = 0; // Block 1 at address 0 (Flash)
    NVM_STORAGE_DTC = 0;
    MemIf_Init();
    // printf("NvM Initialized.\n");
}

FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    Std_ReturnType status;
    if (blockId != NVM_BLOCK_ID_1)
    {
        // printf("NvM WriteBlock Failed: Invalid Block ID %d\n", blockId);
        return RTE_E_INVALID;
    }

    status = MemIf_Write(MEMIF_FLASH, BlockBaseAddress[blockId], data, NVM_BLOCK_SIZE);
    return status;
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data)
{
    Std_ReturnType status;
    if (blockId != NVM_BLOCK_ID_1)
    {
        // printf("NvM ReadBlock Failed: Invalid Block ID %d\n", blockId);
        return RTE_E_INVALID;
    }

    status = MemIf_Read(MEMIF_FLASH, BlockBaseAddress[blockId], data, NVM_BLOCK_SIZE);
    return status;
}

FUNC(Std_ReturnType, NVM_CODE) NvM_WriteDTC(
    VAR(uint16, AUTOMATIC) DTC)
{
    Std_ReturnType status;
    NVM_STORAGE_DTC = DTC;
    status = MemIf_Write(MEMIF_EEPROM, NVM_DTC_ADDRESS, (uint8_t*)&NVM_STORAGE_DTC, NVM_DTC_SIZE);
    return status;
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ReadDTC(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) DTC)
{
    Std_ReturnType status = MemIf_Read(MEMIF_EEPROM, NVM_DTC_ADDRESS, (uint8_t*)DTC, NVM_DTC_SIZE);
    return status;
}

FUNC(Std_ReturnType, NVM_CODE) NvM_ClearDTC(void)
{
    Std_ReturnType status = MemIf_Erase(MEMIF_FLASH, 0, 256); // Erase full flash range
    if (status == RTE_E_OK)
    {
        NVM_STORAGE_DTC = 0;
        // printf("NvM ClearDTC Successful\n");
    }
    return status;
}