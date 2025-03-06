#include "CanIf.h"
#include "../../ECU_Abstraction/ComHwAbstraction/ComHwAbstraction.h"

FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReceiveSpeed(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    return Com_HAL_ReceiveSpeed(speed);
}
