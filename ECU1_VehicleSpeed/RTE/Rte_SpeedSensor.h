#ifndef RTE_SPEED_SENSOR_H
#define RTE_SPEED_SENSOR_H

#include "Std_ReturnType.h"
#include "Compiler.h"
#include "SpeedSensorSWC.h" 
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/**  @brief RTE APIs Prototype Declaration */
/*----------------------------------------------------------------------------*/

/**  @brief Read speed data from sensor */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_SpeedData_ReceiveSpeed(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_ReceiveSpeed Rte_Read_RP_SpeedData_ReceiveSpeed

/**  @brief Call the runnable of Speed Sensor and return speed */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Call_ReadSpeed Rte_Call_RP_SpeedSensorSWC_ReadSpeed

/** @brief RTE Call for OS to call Runnable Rte_Call_SpeedSensorSWC_SendSpeedToCAN*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_SendSpeedToCAN(void);

/** @brief RTE Call for OS to call Runnable SpeedSensorSWC_CheckAndReportError */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_CheckAndReportError(void);

/** @brief RTE Call for OS to call Runnable SpeedSensorSWC_StoreErrorToNVM */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SpeedSensorSWC_SendErrorToNVBlockSWC(void);

#endif /* RTE_SPEED_SENSOR_H */
