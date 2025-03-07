#include "MemIf.h"
#include "MCAL/FlashDriver/Flash.h"
#include <stdio.h>

static VAR(Std_ReturnType, AUTOMATIC) Eep_Write(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    // printf("Eep_Write - Address: 0x%X, Length: %d\n", address, length);
    return RTE_E_OK; // Mock EEPROM write
}

static VAR(Std_ReturnType, AUTOMATIC) Eep_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    // printf("Eep_Read - Address: 0x%X, Length: %d\n", address, length);
    memset(data, 0xEE, length); // Mock EEPROM read (fill with 0xEE)
    return RTE_E_OK;
}

FUNC(void, MEMIF_CODE)
MemIf_Init(void)
{
    // printf("Initializing MemIf...\n");
    FlashDrv_Init();
    // printf("MemIf Initialized.\n");
}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    Std_ReturnType status;
    if (memType == MEMIF_EEPROM)
    {
        status = Eep_Write(address, data, length);
    }
    else if (memType == MEMIF_FLASH)
    {
        status = FlashDrv_Write(address, data, length);
    }
    else
    {
        // printf("MemIf Write Failed: Invalid memory type\n");
        return RTE_E_INVALID;
    }
    return status;
}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    Std_ReturnType status;
    if (memType == MEMIF_EEPROM)
    {
        status = Eep_Read(address, data, length);
    }
    else if (memType == MEMIF_FLASH)
    {
        status = FlashDrv_Read(address, data, length);
    }
    else
    {
        // printf("MemIf Read Failed: Invalid memory type\n");
        return RTE_E_INVALID;
    }

    return status;
}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Erase(
    VAR(MemIf_MemoryType, AUTOMATIC) memType,
    VAR(uint32, AUTOMATIC) address,
    VAR(uint32, AUTOMATIC) length)
{
    if (memType == MEMIF_FLASH)
    {
        return RTE_E_OK;
    }
    // printf("MemIf Erase Failed: Unsupported memory type\n");
    return RTE_E_INVALID;
}