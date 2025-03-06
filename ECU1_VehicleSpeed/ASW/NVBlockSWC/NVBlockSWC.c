#include "NVBlockSWC.h"
#include "Rte_Nvm.h"
#include <stdio.h>

/*------------------------------------------------------------------------------*/
/* Static Variables */
/*------------------------------------------------------------------------------*/
static VAR(uint16_t, NVBLOCK_VAR) storedDTC = 0;

/*------------------------------------------------------------------------------*/
/* Function Implementations */
/*------------------------------------------------------------------------------*/

/**
 * @brief Runnable: Receive DTC from SpeedSensorSWC and store in temporary variable
 */
FUNC(Std_ReturnType, NVBLOCK_CODE)
R_NVBlockSWC_ReceiveDTC(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) DTC)
{
    if (DTC == NULL_PTR)
    {
        return RTE_E_INVALID;
    }

    storedDTC = *DTC;
    return RTE_E_OK;
}

/**
 * @brief Runnable: Save DTC from NVBlock to NVM
 */
FUNC(Std_ReturnType, NVBLOCK_CODE)
R_NVBlockSWC_StoreDTCToNVM(void)
{
    if (storedDTC == 0)
    {
        return RTE_E_NOT_OK;
    }

    /* Call RTE Call to save DTC to NVM */
    VAR(Std_ReturnType, AUTOMATIC)
    statusNVM = Rte_Write_NvmInterface_WriteDTC(storedDTC);

    if (statusNVM == RTE_E_OK)
    {
        return RTE_E_OK;
    }

    return RTE_E_NOT_OK;
}