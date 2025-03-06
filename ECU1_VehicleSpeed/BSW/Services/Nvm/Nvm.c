#include "Nvm.h"
#include "MemIf.h"
#include <stdio.h>

static uint16_t NVM_STORAGE = 0;

/**
 * @brief Save errors to NVM memory
 */
FUNC(Std_ReturnType, NVM_CODE) Nvm_Write(VAR(uint16_t, AUTOMATIC) DTC)
{
    //printf("NVM: Storing DTC %X into memory\n", DTC);

    NVM_STORAGE = DTC;

    if (MemIf_Write(MEMIF_EEPROM, 0x0001, (const uint8_t *)&DTC, sizeof(uint16_t)))
    {
        return RTE_E_OK;
    }
    return RTE_E_NOT_OK;
}

/**
 * @brief Read error from NVM memory
 */
FUNC(Std_ReturnType, NVM_CODE) Nvm_Read(P2VAR(uint16_t, AUTOMATIC, NVM_APPL_DATA) data)
{
    return MemIf_Read(MEMIF_EEPROM, 0x0001, (uint8_t *)data, sizeof(uint16_t)) ? RTE_E_OK : RTE_E_NOT_OK;
}

/**
 * @brief Clear error from NVM memory
 */
FUNC(Std_ReturnType, NVM_CODE) Nvm_Clear(VAR(uint16_t, AUTOMATIC) DTC)
{
    printf("NVM: Clearing DTC %X from memory\n", DTC);

    NVM_STORAGE = 0;

    return MemIf_Erase(MEMIF_FLASH, 0x0000, 0x100) ? RTE_E_OK : RTE_E_NOT_OK;
}
