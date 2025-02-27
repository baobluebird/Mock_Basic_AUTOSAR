#include "Rte_SpeedSensor.h"
#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h" 
#include "ASW/SpeedSensorSWC.h"

void Rte_Call_ReadSpeed(void) {
    R_ReadSpeed();  
}

float Rte_Read_SpeedSensor_Speed(void) {
    return IoHwAb_SpeedSensor_GetSpeed(); 
}
