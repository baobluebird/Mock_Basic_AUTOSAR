#ifndef FI_VALVE_CDD_H
#define FI_VALVE_CDD_H

#include "../Common/Compiler.h"
#include "../RTE/Std_ReturnType.h"

#define FI_VALVE_OFF 0U
#define FI_VALVE_ON  1U

extern FUNC(void, CDD_CODE) FI_ValveCDD_Init(void);

extern FUNC(Std_ReturnType, CDD_CODE) FI_ValveCDD_SetState(
    VAR(uint8, AUTOMATIC) state
);

extern FUNC(Std_ReturnType, CDD_CODE) FI_ValveCDD_GetState(
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) state
);

#endif /* 
void FIControlSWC_Function(void)
{
    uint8 state;
    Std_ReturnType status;

    status = Rte_Write_FIValve_State(FI_VALVE_ON);
    if (status == RTE_E_OK)
    {
        printf("SWC Set FI Valve ON\n");
    }

    status = Rte_Read_FIValve_State(&state);
    if (status == RTE_E_OK)
    {
        printf("SWC Read FI Valve State: %s\n", (state == FI_VALVE_ON) ? "ON" : "OFF");
    }

    status = Rte_Write_FIValve_State(FI_VALVE_OFF);
    if (status == RTE_E_OK)
    {
        printf("SWC Set FI Valve OFF\n");
    }

    status = Rte_Read_FIValve_State(&state);
    if (status == RTE_E_OK)
    {
        printf("SWC Read FI Valve State: %s\n", (state == FI_VALVE_ON) ? "ON" : "OFF");
    }
}   */