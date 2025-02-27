#include "MCAL/ICUDriver/Icu.h"
#include "IoHwAb_SpeedSensor.h"

#define WHEEL_CIRCUMFERENCE 2.0  
#define PULSE_PER_REV 20         

static volatile float vehicleSpeed = 0.0;
static volatile uint32_t pulseInterval = 0;
static volatile uint32_t lastTimestamp = 0;

void IoHwAb_SpeedSensor_Callback(void) {
    uint32_t currentTimestamp = Icu_GetTime(ICU_CHANNEL_SPEED_SENSOR);
    
    if (lastTimestamp > 0) {  
        pulseInterval = currentTimestamp - lastTimestamp;
    }

    lastTimestamp = currentTimestamp;
}

void IoHwAb_SpeedSensor_Init(void) {
    Icu_Init();
    Icu_EnableNotification(ICU_CHANNEL_SPEED_SENSOR, IoHwAb_SpeedSensor_Callback);
}

float IoHwAb_SpeedSensor_GetSpeed(void) {
    if (pulseInterval > 0) {
        float timeSec = pulseInterval / 1000000.0; 
        vehicleSpeed = (WHEEL_CIRCUMFERENCE * PULSE_PER_REV) / timeSec;
    } else {
        vehicleSpeed = 0; 
    }
    
    return vehicleSpeed;
}
