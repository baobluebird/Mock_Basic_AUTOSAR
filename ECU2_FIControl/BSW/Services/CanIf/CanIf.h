#ifndef CANIF_H
#define CANIF_H

#include "Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReceiveSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed);

#endif