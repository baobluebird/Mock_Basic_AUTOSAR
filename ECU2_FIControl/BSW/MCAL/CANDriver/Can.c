#include "Can.h"
#include <stdio.h>

FUNC(void, CAN_CODE)
CanDrv_Init(VAR(void, AUTOMATIC))
{
    // printf("Initializing CAN Driver for ECU2...\n");
    // printf("CAN Driver Initialized.\n");
}

FUNC(Std_ReturnType, CAN_CODE)
CanDrv_Receive(
    P2VAR(uint32_t, AUTOMATIC, RTE_APPL_DATA) CanId,
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) data,
    P2VAR(uint8_t, AUTOMATIC, RTE_APPL_DATA) dlc)
{
    *CanId = CAN_ID_SPEED_DATA;
    *dlc = CAN_DLC_SPEED_DATA;
    
    uint32_t randomSpeed = 11000 + (rand() % (13001 - 11000)); 
    data[0] = (randomSpeed >> 24) & 0xFF;
    data[1] = (randomSpeed >> 16) & 0xFF;
    data[2] = (randomSpeed >> 8) & 0xFF;
    data[3] = randomSpeed & 0xFF;
    
    // printf("CAN Receive - ID: 0x%X, DLC: %d, Data: [", *CanId, *dlc);
    uint8_t i;
    for (i = 0; i < *dlc; i++)
    {
        // printf(" %02X", data[i]);
    }
    // printf(" ]\n");

    return RTE_E_OK;
}