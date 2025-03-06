#include "Rte_Can.h"
#include "../BSW/Services/CanIf/CanIf.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CANMessage(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return CanIf_ReceiveSpeed(speed);
}
