#ifndef COM_HAL_H
#define COM_HAL_H

#include "Std_ReturnType.h"
#include "Compiler.h"

/** @brief CAN ID of vehicle speed */
#define CAN_MSG_ID_SPEED 0x100U

/** @brief Data Length (DLC) */
#define CAN_MSG_DLC_SPEED 4U

/*-------------------------------------------------------------------------------*/
/* Function Prototypes */
/*-------------------------------------------------------------------------------*/

/**
 * @brief Initialize COM HAL
 */
extern FUNC(void, COM_CODE) Com_HAL_Init(VAR(void, AUTOMATIC));

/**
 * @brief Send speed data via CAN
 * @param speed Speed ​​value (float)
 * @return Std_ReturnType - Status of sending data
 */
extern FUNC(Std_ReturnType, COM_CODE) Com_HAL_SendSpeed(VAR(uint16_t, AUTOMATIC) speed);

#endif /* COM_HAL_H */