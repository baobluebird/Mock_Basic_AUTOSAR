#ifndef MEMIF_H
#define MEMIF_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    MEMIF_EEPROM,
    MEMIF_FLASH
} MemIf_MemoryType;

void MemIf_Init(void);
bool MemIf_Write(MemIf_MemoryType memType, uint32_t address, const uint8_t *data, uint32_t length);
bool MemIf_Read(MemIf_MemoryType memType, uint32_t address, uint8_t *data, uint32_t length);
bool MemIf_Erase(MemIf_MemoryType memType, uint32_t address, uint32_t length);

#endif
