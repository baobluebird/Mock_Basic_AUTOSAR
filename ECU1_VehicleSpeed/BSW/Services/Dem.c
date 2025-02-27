#include "Dem.h"
#include "Nvm.h"
#include <stdio.h>

static uint16_t storedDTC = 0;  
static bool errorConfirmed = false;

void Dem_ReportErrorStatus(uint16_t DTC, Dem_EventStatusType status) {
    if (status == DEM_EVENT_STATUS_FAILED) {
        storedDTC = DTC;
        printf("DEM: Error %X reported\n", DTC);

        errorConfirmed = true;

        Dem_NotifySpeedSensorSWC(DTC);
    } else {
        printf("DEM: Error %X cleared\n", DTC);
        storedDTC = 0;
        errorConfirmed = false;
    }
}

bool Dem_CheckErrorConfirmed(uint16_t DTC) {
    return (storedDTC == DTC) && errorConfirmed;
}

void Dem_NotifySpeedSensorSWC(uint16_t DTC) {
    printf("DEM: Notifying SpeedSensorSWC to store DTC %X in NVM\n", DTC);
}