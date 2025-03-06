#include "ComHwAbstraction.h"
#include "../../MCAL/CANDriver/Can.h"
#include <stdio.h>

FUNC(void, COM_CODE) Com_HAL_Init(void)
{
    //printf("Initializing COM HAL for ECU2...\n");
    CanDrv_Init();
   // printf("COM HAL Initialized.\n");
}

FUNC(Std_ReturnType, COM_CODE) Com_HAL_ReceiveSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(uint32_t, AUTOMATIC) canId;
    VAR(uint16_t, AUTOMATIC) data[CAN_MSG_DLC_SPEED];
    VAR(uint8_t, AUTOMATIC) dlc;
    Std_ReturnType status;

    status = CanDrv_Receive(&canId, data, &dlc);
    if (status == RTE_E_OK && dlc >= 4) 
    {    
        VAR(uint32_t, AUTOMATIC) speedInt = ((uint32_t)data[0] << 24) | 
                                            ((uint32_t)data[1] << 16) | 
                                            ((uint32_t)data[2] << 8)  | 
                                            ((uint32_t)data[3]);

        if (speedInt > (UINT16_MAX * 100)) 
        {
            return RTE_E_INVALID;
        }

        *speed = (uint16_t)(speedInt / 100); 
        return RTE_E_OK;
    }
    return RTE_E_INVALID;
}