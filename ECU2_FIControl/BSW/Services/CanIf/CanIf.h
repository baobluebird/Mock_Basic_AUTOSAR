#ifndef CANIF_H
#define CANIF_H

#include "../../../Common/Compiler.h"
#include "../../../RTE/Std_ReturnType.h"

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReceiveSpeed(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed);

#endif
