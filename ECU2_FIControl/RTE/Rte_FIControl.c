#include "Rte_FIControl.h"
#include "BSW/CDD/FI_ValveCDD.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FIValve_State(
    VAR(uint8, AUTOMATIC) state)
{
    return FI_ValveCDD_SetState(state);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FIValve_State(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state)
{
    return FI_ValveCDD_GetState(state);
}