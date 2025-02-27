#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include <stdint.h>

void IoHwAb_SpeedSensor_Init(void);
float IoHwAb_SpeedSensor_GetSpeed(float* speed);

#endif