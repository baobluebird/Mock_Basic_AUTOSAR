#include "ComHwAbstraction.h"
#include "../MCAL/CANDriver/Can.h"
#include <stdio.h>

FUNC(void, COM_CODE) Com_HAL_Init(void)
{
    printf("Initializing COM HAL for ECU2...\n");
    CanDrv_Init();
    printf("COM HAL Initialized.\n");
}

FUNC(Std_ReturnType, COM_CODE) Com_HAL_ReceiveSpeed(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(uint32, AUTOMATIC) canId;
    VAR(uint8, AUTOMATIC) data[CAN_MSG_DLC_SPEED];
    VAR(uint8, AUTOMATIC) dlc;
    Std_ReturnType status;

    status = CanDrv_Receive(&canId, data, &dlc);
    if (status == RTE_E_OK && canId == CAN_MSG_ID_SPEED && dlc == CAN_MSG_DLC_SPEED)
    {
        VAR(uint32, AUTOMATIC) speedInt = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
        *speed = (float)speedInt / 100.0f;
        printf("Received Speed: %.2f\n", *speed);
        return RTE_E_OK;
    }
    return RTE_E_INVALID;
}
