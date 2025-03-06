#include "ComHwAbstraction.h"
#include "Can_Driver.h"
#include <stdio.h>
volatile uint16_t speedCan[CAN_MSG_DLC_SPEED];
/**
 * @brief Initializes COM HAL
 */
FUNC(void, COM_CODE) Com_HAL_Init(VAR(void, AUTOMATIC))
{
    printf("Initializing COM HAL...\n");
    CanDrv_Init();
    printf("COM HAL Initialized.\n");
}

/**
 * @brief Sends speed data via CAN Bus
 */
FUNC(Std_ReturnType, COM_CODE) Com_HAL_SendSpeed(VAR(uint16_t, AUTOMATIC) speed)
{
    VAR(uint16_t, AUTOMATIC) data[CAN_MSG_DLC_SPEED];
    VAR(uint32, AUTOMATIC) speedInt = (uint32)(speed * 100);
		
    data[0] = (speedInt >> 24) & 0xFF;
    data[1] = (speedInt >> 16) & 0xFF;
    data[2] = (speedInt >> 8) & 0xFF;
    data[3] = (speedInt) & 0xFF;
		uint16_t i;
	  for(i = 0; i < CAN_MSG_DLC_SPEED; i++)
	  {
			speedCan[i] = data[i];
		}

    return CanDrv_Transmit(CAN_MSG_ID_SPEED, data, CAN_MSG_DLC_SPEED);
}