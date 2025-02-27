#include "MCAL/ICUDriver/Icu.h"
#include "IoHwAb_SpeedSensor.h"
#include "RTE/Std_ReturnType.h"

#define WHEEL_CIRCUMFERENCE 2.0  
#define PULSE_PER_REV 20         

static volatile float vehicleSpeed = 0.0;
static volatile uint32_t pulseInterval = 0;
static volatile uint32_t lastTimestamp = 0;

void IoHwAb_SpeedSensor_Callback(void) {
    uint32_t currentTimestamp = Icu_GetTime(ICU_CHANNEL_SPEED_SENSOR);
    
    if (lastTimestamp > 0) {  
        uint32_t newInterval = currentTimestamp - lastTimestamp;
        if (newInterval > 0) {
            pulseInterval = newInterval;
        }
    }

    lastTimestamp = currentTimestamp;
}

void IoHwAb_SpeedSensor_Init(void) {
    Icu_Init();
    Icu_EnableNotification(ICU_CHANNEL_SPEED_SENSOR, IoHwAb_SpeedSensor_Callback);
}

Std_ReturnType IoHwAb_SpeedSensor_GetSpeed(float* speed) {
    if (pulseInterval > 0) {
        float timeSec = pulseInterval / 1000000.0; 
        *speed = (WHEEL_CIRCUMFERENCE * PULSE_PER_REV) / timeSec;
        return RTE_E_OK;
    } else {
        *speed = 0; 
        return RTE_E_NO_DATA;
    }
}
