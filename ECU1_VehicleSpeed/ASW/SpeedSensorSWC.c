#include "SpeedSensorSWC.h"
#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h" 
#include "../RTE/Rte_Dem.h"
#include "BSW\Services\Nvm.h"
static float vehicleSpeed = 0.0;

void SpeedSensorSWC_Init(void) {
    //init something
}

//Runnable
float R_ReadSpeed(void) {
    vehicleSpeed = Rte_Read_SpeedSensor_Speed();
    printf("Vehicle Speed: %.2f m/s\n", vehicleSpeed);

    if (vehicleSpeed > 120.0) {
        Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_FAILED);
    } else {
        Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_PASSED);
    }
}

void SpeedSensorSWC_MainFunction(void) {
    R_ReadSpeed();
}

float SpeedSensorSWC_GetSpeed(void) {
    return vehicleSpeed;
}

void SpeedSensorSWC_HandleError(uint16_t DTC) {
    if (Dem_CheckErrorConfirmed(DTC)) {
        printf("SpeedSensorSWC: Storing confirmed DTC %X in NVM\n", DTC);
        Nvm_WriteBlock(&DTC);
    }
}
