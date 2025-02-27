#include "Rte_Dem.h"
#include "ASW\SpeedSensorSWC.h"

void Rte_Dem_ReportError(uint16_t DTC, Dem_EventStatusType status) {
    Dem_ReportErrorStatus(DTC, status);
}

void Rte_Dem_NotifySpeedSensorSWC(uint16_t DTC) {
    SpeedSensorSWC_HandleError(DTC);
}
