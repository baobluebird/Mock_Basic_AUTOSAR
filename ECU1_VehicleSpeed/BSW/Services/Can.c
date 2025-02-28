#include "Can.h"
#include "ECU_Abstraction/ComHwAbstraction/ComHwAbstraction.h"

/**
 * @brief Sends speed data via CAN Services
 */
FUNC(Std_ReturnType, CAN_CODE) Can_Services_SendSpeed(VAR(float, AUTOMATIC) speed)
{
    return Com_HAL_SendSpeed(speed);
}