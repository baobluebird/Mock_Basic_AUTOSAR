#include "Rte_SpeedSensor.h"
#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h"
#include "ASW/SpeedSensorSWC.h"
#include "Std_ReturnType.h"
#include <stdio.h>

/****************************************************************************/
/**  @brief Read speed from sensor (Rte_Read) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_SpeedData_ReceiveSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;

    if (speed == NULL_PTR) 
    {
        printf("Error: Rte_Read_ReceiveSpeed - Null pointer!\n");
        return RTE_E_INVALID;
    }

    ret_val = IoHwAb_SpeedSensor_GetSpeed(speed);

    if (ret_val != RTE_E_OK)
    {
        printf("Error: Failed to read speed from sensor. Code: %d\n", ret_val);
    }

    return ret_val;
}

/****************************************************************************/
/**  @brief Call the ReadSpeed function in SWC (Rte_Call) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) status;

    if (speed == NULL_PTR) 
    {
        printf("Error: Rte_Call_RP_SpeedSensorSWC_ReadSpeed - Null pointer!\n");
        return RTE_E_INVALID;
    }

    status = R_ReadSpeed(speed);

    if (status != RTE_E_OK)
    {
        printf("Error: Rte_Call_SpeedSensor_ReadSpeed failed with error code %d\n", status);
    }

    return status;
}
