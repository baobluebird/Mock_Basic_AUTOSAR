#include "SpeedSensorSWC.h"
#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h" 
#include "../RTE/Rte_Dem.h"
#include "BSW\Services\Nvm.h"
#include "RTE\Std_ReturnType.h"
static float vehicleSpeed = 0.0;

void SpeedSensorSWC_Init(void) {
    //init something
}

//Runnable
Std_ReturnType R_ReadSpeed(void) {
    float speed;
    Std_ReturnType status = Rte_Read_SpeedSensor_Speed(&speed);

    if (status == RTE_E_OK) {
        vehicleSpeed = speed;
        printf("Vehicle Speed: %.2f m/s\n", vehicleSpeed);

        if (vehicleSpeed > 120.0) {
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_FAILED);
        } else {
            Rte_Dem_ReportError(DTC_SPEED_LIMIT_EXCEEDED, DEM_EVENT_STATUS_PASSED);
        }
    } else {
        printf("Error: Unable to read speed from sensor (Error Code: %d)\n", status);
    }

    return status;
}

void SpeedSensorSWC_MainFunction(void) {
    Std_ReturnType status = R_ReadSpeed();
    if (status != RTE_E_OK) {
        SpeedSensorSWC_HandleError(DTC_SENSOR_FAILURE);
    }
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
