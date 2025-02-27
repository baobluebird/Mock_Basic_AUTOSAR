#ifndef DEM_H
#define DEM_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    DEM_EVENT_STATUS_PASSED,
    DEM_EVENT_STATUS_FAILED,
    DEM_EVENT_STATUS_CONFIRMED  
} Dem_EventStatusType;

// DTC ID
#define DTC_SPEED_SENSOR_FAILURE  0x1234
#define DTC_SPEED_LIMIT_EXCEEDED  0x5678
#define DTC_NVM_WRITE_ERROR       0x9101
#define DTC_SENSOR_FAILURE        0x1122

void Dem_ReportErrorStatus(uint16_t DTC, Dem_EventStatusType status);
bool Dem_CheckErrorConfirmed(uint16_t DTC);
void Dem_NotifySpeedSensorSWC(uint16_t DTC);

#endif // DEM_H
