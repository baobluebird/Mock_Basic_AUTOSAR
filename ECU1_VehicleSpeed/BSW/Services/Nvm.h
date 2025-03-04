#ifndef NVM_H
#define NVM_H

#include <stdint.h>
#include <stdbool.h>
#include "Std_ReturnType.h"
#include "Compiler.h"

extern FUNC(Std_ReturnType, NVM_CODE) Nvm_Write(VAR(uint16_t, AUTOMATIC) DTC);
extern FUNC(Std_ReturnType, NVM_CODE) Nvm_Read(P2VAR(uint16_t, AUTOMATIC, NVM_APPL_DATA) data);
extern FUNC(Std_ReturnType, NVM_CODE) Nvm_Clear(VAR(uint16_t, AUTOMATIC) DTC);

#endif // NVM_H
