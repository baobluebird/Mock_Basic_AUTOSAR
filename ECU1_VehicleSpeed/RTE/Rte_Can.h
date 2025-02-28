#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "Std_ReturnType.h"
#include "Common/Compiler.h"

/**
 * @brief Send speed data from SWC via RTE to CAN
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CANMessage(VAR(float, AUTOMATIC) speed);

#endif /* RTE_CAN_H */
