#include "Rte_SpeedSensor.h"
#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h" 
#include "ASW/SpeedSensorSWC.h"
#include "Std_ReturnType.h"

void Rte_Call_ReadSpeed(void) {
    R_ReadSpeed();  
}

Std_ReturnType Rte_Read_SpeedSensor_Speed(float* speed) {
    return IoHwAb_SpeedSensor_GetSpeed(speed);
}