#ifndef CAN_DRIVER_ECU2_H
#define CAN_DRIVER_ECU2_H

#include "Std_ReturnType.h"
#include "Compiler.h"

#define CAN_ID_SPEED_DATA 0x100U

#define CAN_DLC_SPEED_DATA 4U

extern FUNC(void, CAN_CODE) CanDrv_Init(VAR(void, AUTOMATIC));

extern FUNC(Std_ReturnType, CAN_CODE) CanDrv_Receive(
    P2VAR(uint32_t, AUTOMATIC, RTE_APPL_DATA) CanId,
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) dlc
);

#endif /* CAN_DRIVER_H */