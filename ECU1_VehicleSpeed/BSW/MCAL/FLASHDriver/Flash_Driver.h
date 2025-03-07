#ifndef FLASH_DRIVER_H
#define FLASH_DRIVER_H

#include "Std_Types.h"
#include "Compiler.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define FLASH_BLOCK_SIZE 64U
#define FLASH_TOTAL_SIZE 256U

bool Eep_Write(uint32_t address, const uint8_t *data, uint32_t length);

bool Eep_Read(uint32_t address, uint8_t *data, uint32_t length);

bool Fls_Write(uint32_t address, const uint8_t *data, uint32_t length);

bool Fls_Read(uint32_t address, uint8_t *data, uint32_t length);

void Fls_Erase(uint32_t address, uint32_t length);
#endif