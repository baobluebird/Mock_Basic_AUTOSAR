#include "Icu.h"
#include <stdio.h>

static volatile uint32_t lastTimestamp = 0;
static volatile uint32_t pulseInterval = 0;

uint32_t Icu_GetTime(uint8_t channel) {
    return (uint32_t)(clock() * 1000); 
}

void Icu_SpeedSensorCallback(void) {
    uint32_t currentTimestamp = Icu_GetTime(ICU_CHANNEL_SPEED_SENSOR);
    pulseInterval = currentTimestamp - lastTimestamp;
    lastTimestamp = currentTimestamp;
}

void Icu_Setup(uint8_t channel, Icu_CallbackType callback) {
    if (channel == ICU_CHANNEL_SPEED_SENSOR) {
        Icu_EnableNotification(channel, callback);
    }
}

void Icu_EnableNotification(uint8_t channel, Icu_CallbackType callback) {
    if (channel == ICU_CHANNEL_SPEED_SENSOR) {
        callback(); 
    }
}

void Icu_Init(void) {
    Icu_Setup(ICU_CHANNEL_SPEED_SENSOR, Icu_SpeedSensorCallback);
}
