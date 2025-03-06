
#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "Compiler.h"
#include "Std_ReturnType.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed);

#endif /* RTE_CAN_H */
