#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include <stdint.h>

#include "MCAL/ICUDriver/Icu.h"
#include "RTE/Std_ReturnType.h"

#define WHEEL_CIRCUMFERENCE 2.0  
#define PULSE_PER_REV 20    

void IoHwAb_SpeedSensor_Init(void);
Std_ReturnType IoHwAb_SpeedSensor_GetSpeed(float* speed);

#endif