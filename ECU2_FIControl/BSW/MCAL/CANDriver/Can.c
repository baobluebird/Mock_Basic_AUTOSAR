#include "Can.h"
#include <stdio.h>

FUNC(void, CAN_CODE)
CanDrv_Init(VAR(void, AUTOMATIC))
{
    printf("Initializing CAN Driver for ECU2...\n");
    printf("CAN Driver Initialized.\n");
}

FUNC(Std_ReturnType, CAN_CODE) CanDrv_Receive(
    P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) CanId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dlc)
{
    *CanId = CAN_ID_SPEED_DATA;
    *dlc = CAN_DLC_SPEED_DATA;

    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = 0x63;
    data[3] = 0xFC;

    printf("CAN Receive - ID: 0x%X, DLC: %d, Data: [", *CanId, *dlc);
    for (int i = 0; i < *dlc; i++)
    {
        printf(" %02X", data[i]);
    }
    printf(" ]\n");

    return RTE_E_OK;
}
