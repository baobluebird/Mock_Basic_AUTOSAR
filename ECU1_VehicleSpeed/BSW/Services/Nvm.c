#include "Nvm.h"
#include "ECU_Abstraction/MemIf/MemIf.h"
#include <stdio.h>

static uint8_t NVM_STORAGE[10];
 

bool Nvm_WriteBlock(const uint16_t *data) {
    printf("NVM: Stored DTC %X\n", *data);
    return MemIf_Write(MEMIF_EEPROM, 0x0001, (const uint8_t*)data, sizeof(uint16_t));
}

bool Nvm_ReadBlock(uint16_t *data) {
    return MemIf_Read(MEMIF_EEPROM, 0x0001, (uint8_t*)data, sizeof(uint16_t));
}

void Nvm_EraseBlock(void) {
    MemIf_Erase(MEMIF_FLASH, 0x0000, 0x100);
}