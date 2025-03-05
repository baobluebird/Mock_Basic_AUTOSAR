#ifndef SPEED_SENSOR_SWC_H
#define SPEED_SENSOR_SWC_H

#include "Rte_SpeedSensor.h"
#include "Std_ReturnType.h"
#include "Compiler.h"

/*-----------------------------------------------------------------------------------------*/
/* Memory Mapping Definitions (AUTOSAR) */
/*-------------------------------------------------------------------------------*/

/* Defines memory partition for Speed ​​Sensor SWC Code */
#define SPEEDSENSOR_CODE RTE_CODE

/* Defines memory partition for Speed ​​Sensor SWC Variables */
#define SPEEDSENSOR_VAR RTE_VAR_NOINIT

/*------------------------------------------------------------------------------*/
/* Function Prototypes */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes Speed ​​Sensor SWC
 */
extern FUNC(void, SPEEDSENSOR_CODE) R_SpeedSensorSWC_Init(VAR(void, AUTOMATIC));
/**
* @brief Runnable: Check for errors and report errors to DEM
* @return Std_ReturnType - Execution status (RTE_E_OK or RTE_E_NOT_OK)
*/
extern FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_CheckAndReportError(void);

/**
* @brief Runnable: Save error to NVM if error has been acknowledged by DEM
* @return Std_ReturnType - Execution status (RTE_E_OK or RTE_E_NOT_OK)
*/
extern FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_StoreErrorToNVM(void);

/**
* @brief Runnable: Send speed data to CAN
* @return Std_ReturnType - Execution status (RTE_E_OK or RTE_E_NOT_OK)
*/
extern FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_SpeedSensorSWC_SendSpeedToCAN(void);

/**
* @brief Runnable: Read speed from sensor
* @return Std_ReturnType - Data reading status
*/
extern FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_ReadSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA));

#endif /* SPEED_SENSOR_SWC_H */