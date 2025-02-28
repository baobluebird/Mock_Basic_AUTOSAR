#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include "RTE/Std_ReturnType.h"
#include "Common/Compiler.h"

/** @brief CAN ID for Speed ​​Data */
#define CAN_ID_SPEED_DATA 0x100U

/** @brief Data length (DLC) */
#define CAN_DLC_SPEED_DATA 4U

/*------------------------------------------------------------------------------*/
/* Function Prototypes */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initialize CAN Driver
 */
extern FUNC(void, CAN_CODE) CanDrv_Init(VAR(void, AUTOMATIC));

/**
 * @brief Send CAN data
 * @param CanId ID of CAN Message
 * @param data Pointer to data buffer
 * @param dlc Data length (DLC)
 * @return Std_ReturnType - Data sending status
 */
extern FUNC(Std_ReturnType, CAN_CODE) CanDrv_Transmit(VAR(uint32, AUTOMATIC) CanId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint8, AUTOMATIC) dlc);

#endif /* CAN_DRIVER_H */