#include "Flash.h"
#include <stdio.h>
#include <string.h>

static VAR(uint8, AUTOMATIC) FlashMemory[FLASH_TOTAL_SIZE] = {0};

FUNC(void, FLASH_CODE)
FlashDrv_Init(void)
{
    printf("Initializing Flash Driver...\n");
    memset(FlashMemory, 0xFF, FLASH_TOTAL_SIZE);
    printf("Flash Driver Initialized. Memory set to 0xFF.\n");
}

FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Write(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    if (address + length > FLASH_TOTAL_SIZE)
    {
        printf("Flash Write Failed: Address out of range or length too large\n");
        return RTE_E_INVALID;
    }

    memcpy(&FlashMemory[address], data, length);
    printf("Flash Write - Address: 0x%X, Length: %d, Data: [", address, length);
    for (VAR(uint32, AUTOMATIC) i = 0; i < length; i++)
    {
        printf(" %02X", FlashMemory[address + i]);
    }
    printf(" ]\n");

    return RTE_E_OK;
}

FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    if (address + length > FLASH_TOTAL_SIZE)
    {
        printf("Flash Read Failed: Address out of range or length too large\n");
        return RTE_E_INVALID;
    }

    memcpy(data, &FlashMemory[address], length);
    printf("Flash Read - Address: 0x%X, Length: %d, Data: [", address, length);
    for (VAR(uint32, AUTOMATIC) i = 0; i < length; i++)
    {
        printf(" %02X", data[i]);
    }
    printf(" ]\n");

    return RTE_E_OK;
}