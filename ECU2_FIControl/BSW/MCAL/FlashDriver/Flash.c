#include "Flash.h"
#include <string.h>

static VAR(uint8, AUTOMATIC) FlashMemory[FLASH_TOTAL_SIZE] = {0};

FUNC(void, FLASH_CODE)
FlashDrv_Init(void)
{
    memset(FlashMemory, 0xFF, FLASH_TOTAL_SIZE);
}

FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Write(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    if (address + length > FLASH_TOTAL_SIZE)
    {
        return RTE_E_INVALID;
    }

    memcpy(&FlashMemory[address], data, length);
    return RTE_E_OK;
}

FUNC(Std_ReturnType, FLASH_CODE) FlashDrv_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    if (address + length > FLASH_TOTAL_SIZE)
    {
        return RTE_E_INVALID;
    }

    memcpy(data, &FlashMemory[address], length);
    return RTE_E_OK;
}