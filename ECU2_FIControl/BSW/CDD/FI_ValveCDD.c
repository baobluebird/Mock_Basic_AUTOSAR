#include "FI_ValveCDD.h"
#include <stdio.h>

static VAR(uint8, AUTOMATIC) ValveState = FI_VALVE_OFF;

FUNC(void, CDD_CODE)
FI_ValveCDD_Init(void)
{
    //printf("Initializing FI Valve CDD...\n");
    ValveState = FI_VALVE_OFF;
    //printf("FI Valve CDD Initialized. Valve State: OFF\n");
}

FUNC(Std_ReturnType, CDD_CODE) FI_ValveCDD_SetState(
    VAR(uint8, AUTOMATIC) state)
{
    if (state != FI_VALVE_OFF && state != FI_VALVE_ON)
    {
        //printf("FI Valve Set Failed: Invalid State %d\n", state);
        return RTE_E_INVALID;
    }

    ValveState = state;
    //printf("FI Valve Set State: %s\n", (state == FI_VALVE_ON) ? "ON" : "OFF");
    return RTE_E_OK;
}

FUNC(Std_ReturnType, CDD_CODE) FI_ValveCDD_GetState(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state)
{
    *state = ValveState;
    //printf("FI Valve Get State: %s\n", (ValveState == FI_VALVE_ON) ? "ON" : "OFF");
    return RTE_E_OK;
}