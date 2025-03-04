#include "Rte_SpeedSensor.h"
#include "IoHwAb_SpeedSensor.h"
#include "SpeedSensorSWC.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/****************************************************************************/
/**  @brief Read speed from sensor (Rte_Read) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_SpeedData_ReceiveSpeed(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    ret_val = IoHwAb_SpeedSensor_GetSpeed(speed);
    if (speed == NULL_PTR) 
    {
       //printf("Error: Rte_Read_ReceiveSpeed - Null pointer!\n");
        return ret_val;
    }

    return ret_val;
}

/****************************************************************************/
/**  @brief Call the ReadSpeed function in SWC (Rte_Call) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) status;

    if (speed == NULL_PTR) 
    {
        //printf("Error: Rte_Call_RP_SpeedSensorSWC_ReadSpeed - Null pointer!\n");
        return RTE_E_INVALID;
    }

    status = R_ReadSpeed(speed);

    if (status != RTE_E_OK)
    {
       // printf("Error: Rte_Call_SpeedSensor_ReadSpeed failed with error code %d\n", status);
    }

    return status;
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_CheckAndReportError */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_CheckAndReportError(void)
{
    return SpeedSensorSWC_CheckAndReportError();
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_StoreErrorToNVM */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_StoreErrorToNVM(void)
{
    return SpeedSensorSWC_StoreErrorToNVM();
}

