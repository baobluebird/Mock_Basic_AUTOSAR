#ifndef COM_HAL_H
#define COM_HAL_H

#include "../../../Common/Compiler.h"
#include "../../../RTE/Std_ReturnType.h"

#define CAN_MSG_ID_SPEED 0x100U

#define CAN_MSG_DLC_SPEED 4U

extern FUNC(void, COM_CODE) Com_HAL_Init(void);

extern FUNC(Std_ReturnType, COM_CODE) Com_HAL_ReceiveSpeed(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed);

#endif
