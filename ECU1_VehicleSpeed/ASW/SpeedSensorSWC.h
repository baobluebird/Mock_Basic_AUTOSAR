#ifndef SPEED_SENSOR_SWC_H
#define SPEED_SENSOR_SWC_H

#include <stdint.h>

void SpeedSensorSWC_Init(void);

//Runnable
float R_ReadSpeed(void);

void SpeedSensorSWC_MainFunction(void);
float SpeedSensorSWC_GetSpeed(void);

void SpeedSensorSWC_HandleError(uint16_t DTC);
#endif 
