#ifndef ICU_H
#define ICU_H

#include <stdint.h>

#define ICU_CHANNEL_SPEED_SENSOR   0  

typedef void (*Icu_CallbackType)(void);

void Icu_Init(void);
void Icu_Setup(uint8_t channel, Icu_CallbackType callback);
uint32_t Icu_GetTime(uint8_t channel);
void Icu_EnableNotification(uint8_t channel, Icu_CallbackType callback);

#endif 