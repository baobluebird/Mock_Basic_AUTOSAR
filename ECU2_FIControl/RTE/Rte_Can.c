#include "../RTE/Rte_Can.h"
#include "CanIf.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return CanIf_ReceiveSpeed(speed);
}