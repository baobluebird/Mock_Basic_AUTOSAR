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
FUNC(Std_ReturnType, CAN_CODE) CanDrv_Transmit(VAR(uint32, AUTOMATIC) CanId, P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) data, VAR(uint16_t, AUTOMATIC) dlc)
{
    //printf("CAN Transmit - ID: 0x%X, DLC: %d, Data: [", CanId, dlc);
    uint8_t i;
    for (i = 0; i < dlc; i++)
    {
        //printf(" %02X", data[i]);
    }
    //printf(" ]\n");

    return RTE_E_OK;
}