#ifndef RTE_DEM_H
#define RTE_DEM_H

#include "BSW\Services\Dem.h"

void Rte_Dem_ReportError(uint16_t DTC, Dem_EventStatusType status);

void Rte_Dem_NotifySpeedSensorSWC(uint16_t DTC);

#endif 