#include "MemIf.h"
#include <stdio.h>

void MemIf_Init(void) {
    printf("MemIf: Initialized\n");
}

bool Eep_Write(uint32_t address, const uint8_t *data, uint32_t length) {
    //printf("Eep_Write called at address 0x%X with length %d\n", address, length);
    return true; 
}

bool Eep_Read(uint32_t address, uint8_t *data, uint32_t length) {
    //printf("Eep_Read called at address 0x%X with length %d\n", address, length);
    return true; // Giả lập đọc thành công
}

bool Fls_Write(uint32_t address, const uint8_t *data, uint32_t length) {
    //printf("Fls_Write called at address 0x%X with length %d\n", address, length);
    return true; 
}
bool Fls_Read(uint32_t address, uint8_t *data, uint32_t length) {
    //printf("Fls_Read called at address 0x%X with length %d\n", address, length);
    return true; // Giả lập đọc thành công
}

void Fls_Erase(uint32_t address, uint32_t length) {
    //printf("Fls_Erase called at address 0x%X with length %d\n", address, length);
}


bool MemIf_Write(MemIf_MemoryType memType, uint32_t address, const uint8_t *data, uint32_t length) {
    if (memType == MEMIF_EEPROM) {
        return Eep_Write(address, data, length);
    } else if (memType == MEMIF_FLASH) {
        return Fls_Write(address, data, length);
    }
    return false;
}

bool MemIf_Read(MemIf_MemoryType memType, uint32_t address, uint8_t *data, uint32_t length) {
    if (memType == MEMIF_EEPROM) {
        return Eep_Read(address, data, length);
    } else if (memType == MEMIF_FLASH) {
        return Fls_Read(address, data, length);
    }
    return false;
}

bool MemIf_Erase(MemIf_MemoryType memType, uint32_t address, uint32_t length) {
    if (memType == MEMIF_FLASH) {
        Fls_Erase(address, length);
        return true;
    }
    return false;
}
