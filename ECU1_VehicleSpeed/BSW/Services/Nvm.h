#ifndef NVM_H
#define NVM_H

#include <stdint.h>
#include <stdbool.h>

bool Nvm_WriteBlock(const uint16_t *data);
bool Nvm_ReadBlock(uint16_t *data);
void Nvm_EraseBlock(void);

#endif // NVM_H
