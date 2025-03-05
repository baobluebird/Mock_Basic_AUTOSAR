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
    VAR(Std_ReturnType, AUTOMATIC) status;

    status = IoHwAb_SpeedSensor_GetSpeed(speed);

    return status;
}

/****************************************************************************/
/**  @brief Call the ReadSpeed function in SWC (Rte_Call) */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    
    status = R_ReadSpeed(speed);
    
    return status;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_SendSpeedToCAN(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    status = R_SpeedSensorSWC_SendSpeedToCAN();
    return status;
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_CheckAndReportError */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_CheckAndReportError(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    status = R_SpeedSensorSWC_CheckAndReportError();
    return status;
}

/****************************************************************************/
/**  @brief RTE Call to OS call Runnable SpeedSensorSWC_StoreErrorToNVM */
/****************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_SendErrorToNVBlockSWC(void)
{
    VAR(Std_ReturnType, AUTOMATIC) status;
    status = R_SpeedSensorSWC_SendErrorToNVBlockSWC();
    return status;
}

