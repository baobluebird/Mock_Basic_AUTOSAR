#ifndef SPEED_SENSOR_SWC_H
#define SPEED_SENSOR_SWC_H

#include "Rte_SpeedSensor.h"
#include "Std_ReturnType.h"

/*-----------------------------------------------------------------------------------------*/
/* Memory Mapping Definitions (AUTOSAR) */
/*-------------------------------------------------------------------------------*/

/* Defines memory partition for Speed ​​Sensor SWC Code */
#define SPEEDSENSOR_CODE RTE_CODE

/* Defines memory partition for Speed ​​Sensor SWC Variables */
#define SPEEDSENSOR_VAR RTE_VAR_NOINIT

/*-------------------------------------------------------------------------------*/
/* DTC (Diagnostic Trouble Code) Definitions */
/*-------------------------------------------------------------------------------*/

#define DTC_SPEED_LIMIT_EXCEEDED 0x1001
#define DTC_SENSOR_FAILURE 0x1002

/*------------------------------------------------------------------------------*/
/* Function Prototypes */
/*------------------------------------------------------------------------------*/

/**
 * @brief Initializes Speed ​​Sensor SWC
 */
extern FUNC(void, SPEEDSENSOR_CODE) SpeedSensorSWC_Init(VAR(void, AUTOMATIC));

/**
* @brief Runnable: Read speed from sensor
* @return Std_ReturnType - Data reading status
*/
extern FUNC(Std_ReturnType, SPEEDSENSOR_CODE) R_ReadSpeed(VAR(void, AUTOMATIC));

