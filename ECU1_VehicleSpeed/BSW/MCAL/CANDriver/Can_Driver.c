#include "Can_Driver.h"
#include <stdio.h>

/**
 * @brief Initialize CAN Driver
 */
FUNC(void, CAN_CODE) CanDrv_Init(VAR(void, AUTOMATIC))
{
    printf("Initializing CAN Driver...\n");
    printf("CAN Driver Initialized.\n");
}

/**
 * @brief Send CAN data
 */
FUNC(Std_ReturnType, CAN_CODE) CanDrv_Transmit(VAR(uint32, AUTOMATIC) CanId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint8, AUTOMATIC) dlc)
{
    printf("CAN Transmit - ID: 0x%X, DLC: %d, Data: [", CanId, dlc);
    for (int i = 0; i < dlc; i++)
    {
        printf(" %02X", data[i]);
    }
    printf(" ]\n");

    return RTE_E_OK;
}