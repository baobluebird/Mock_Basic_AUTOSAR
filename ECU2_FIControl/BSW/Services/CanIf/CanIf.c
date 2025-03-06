#include "CanIf.h"
#include "../../ECU_Abstraction/COMAbstraction/ComHwAbstraction.h"

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReceiveSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return Com_HAL_ReceiveSpeed(speed);
}