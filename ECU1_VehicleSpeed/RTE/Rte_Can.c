#include "Rte_Can.h"
#include "Can.h"

/**
 * @brief Send speed data from SWC via RTE to CAN
 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CANMessage(VAR(uint16_t, AUTOMATIC) speed)
{
    return Can_Services_SendSpeed(speed);
}
