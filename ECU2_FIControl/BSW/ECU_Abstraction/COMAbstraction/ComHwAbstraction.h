#ifndef COM_HAL_ECU2_H
#define COM_HAL_ECU2_H

#include "Compiler.h"
#include "Std_ReturnType.h"

#define CAN_MSG_ID_SPEED 0x100U

#define CAN_MSG_DLC_SPEED 4U

extern FUNC(void, COM_CODE) Com_HAL_Init(void);

extern FUNC(Std_ReturnType, COM_CODE) Com_HAL_ReceiveSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed);

#endif