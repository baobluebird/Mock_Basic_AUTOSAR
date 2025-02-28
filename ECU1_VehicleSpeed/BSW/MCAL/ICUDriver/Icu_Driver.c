#include "Icu_Driver.h"
#include <stdio.h>
#include <time.h>

/*--------------------------------------------------------------------------------------------*/
/* Static Variables */
/*-------------------------------------------------------------------------------*/

/** @brief Previous time of sensor pulse */
static volatile VAR(uint32, ICU_VAR) lastTimestamp = 0U;

/** @brief Time interval between two pulses */
static volatile VAR(uint32, ICU_VAR) pulseInterval = 0U;

/*-------------------------------------------------------------------------*/
/* Function Implementations */
/*-------------------------------------------------------------------------------*/

/**
 * @brief Get the time value of the ICU channel
 */
FUNC(uint32, ICU_CODE) Icu_GetTime(VAR(uint8, AUTOMATIC) channel)
{
    /* Simulate time with clock() */
    return (uint32)(clock() * 1000U);
}

/**
 * @brief Callback to process data from the speed sensor
 */
FUNC(void, ICU_APPL_CODE) Icu_SpeedSensorCallback(void)
{
    VAR(uint32, AUTOMATIC) currentTimestamp = Icu_GetTime(ICU_CHANNEL_SPEED_SENSOR);

    if (lastTimestamp > 0U)
    {
        pulseInterval = currentTimestamp - lastTimestamp;
    }

    lastTimestamp = currentTimestamp;
}

/**
 * @brief Configure ICU for specific channel
 */
FUNC(void, ICU_CODE) Icu_Setup(VAR(uint8, AUTOMATIC) channel, VAR(Icu_CallbackType, AUTOMATIC) callback)
{
    if (channel == ICU_CHANNEL_SPEED_SENSOR)
    {
        Icu_EnableNotification(channel, callback);
    }
}

/**
 * @brief Enables interrupt notifications for the ICU channel
 */
FUNC(void, ICU_CODE) Icu_EnableNotification(VAR(uint8, AUTOMATIC) channel, VAR(Icu_CallbackType, AUTOMATIC) callback)
{
    if (channel == ICU_CHANNEL_SPEED_SENSOR && callback != NULL_PTR)
    {
        callback();
    }
}

/**
 * @brief Initializes ICU Driver
 */
FUNC(void, ICU_CODE) Icu_Init(VAR(void, AUTOMATIC))
{
    printf("Initializing ICU Driver...\n");
    Icu_Setup(ICU_CHANNEL_SPEED_SENSOR, Icu_SpeedSensorCallback);
    printf("ICU Driver Initialized.\n");
}