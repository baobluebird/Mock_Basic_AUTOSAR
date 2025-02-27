#ifndef RTE_SPEED_SENSOR_H
#define RTE_SPEED_SENSOR_H

#include <stdint.h>

void Rte_Call_ReadSpeed(void);

Std_ReturnType Rte_Read_SpeedSensor_Speed(float* speed);

#endif 
