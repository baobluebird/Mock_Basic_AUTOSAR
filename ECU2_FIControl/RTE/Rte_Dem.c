#include "../RTE/Rte_Dem.h"
#include "../BSW/Services/Nvm/Nvm.h"
#include "FIControlSWC.h"
#include "../BSW/Services/Dem/Dem.h"

/*-------------------------------------------------------------------------*/
/* Function Implementations */
/*-------------------------------------------------------------------------------*/

/**
 * @brief Report diagnostic errors to DEM
 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_ReportErrorStatus(VAR(uint16, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status)
{
    if (DTC == 0)
    {
        return RTE_E_INVALID;
    }

    Dem_ReportErrorStatus(DTC, status);

    return RTE_E_OK;
}


FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemInterface_ErrorConfirmed(VAR(uint16_t, AUTOMATIC) DTC)
{
    //printf("RTE: SWC notified that DTC %X is confirmed\n", DTC);
    return RTE_E_OK;
}