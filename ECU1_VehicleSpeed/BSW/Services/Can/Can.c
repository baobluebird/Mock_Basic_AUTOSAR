#include "Can.h"
#include "ComHwAbstraction.h"

/**
 * @brief Sends speed data via CAN Services
 */
FUNC(Std_ReturnType, CAN_CODE) Can_Services_SendSpeed(VAR(uint16_t, AUTOMATIC) speed)
{
    return Com_HAL_SendSpeed(speed);
}