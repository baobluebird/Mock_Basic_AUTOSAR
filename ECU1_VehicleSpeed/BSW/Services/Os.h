#ifndef OS_H
#define OS_H

#include "../../RTE/Rte_SpeedSensor.h"

void Os_Init(void);
void Os_Start(void);
void Sensor_Read_Task(void);  

#endif 
