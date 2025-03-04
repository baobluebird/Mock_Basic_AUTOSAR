#include "IoHwAb_SpeedSensor.h"
#include <stdio.h>

/*--------------------------------------------------------------------------------------------*/
/* Static Variables */
/*-------------------------------------------------------------------------------*/
/** @brief Store the time interval between two pulses */
static volatile VAR(uint32, IOHWAB_VAR) pulseInterval = 0U;

/** @brief Store the timestamp of the previous pulse */
static volatile VAR(uint32, IOHWAB_VAR) lastTimestamp = 0U;

/*------------------------------------------------------------------------------*/
/* Callback Function */
/*------------------------------------------------------------------------------*/

/**
 * @brief Callback processes data from the ICU Driver when there is a pulse from the speed sensor
 */
FUNC(void, IOHWAB_CODE) IoHwAb_SpeedSensor_Callback(void)
{
    VAR(uint32, AUTOMATIC) currentTimestamp = Icu_GetTime(ICU_CHANNEL_SPEED_SENSOR);

    if (lastTimestamp > 0U)
    {
        VAR(uint32, AUTOMATIC) newInterval = currentTimestamp - lastTimestamp;
        if (newInterval > 0U)
        {
            pulseInterval = newInterval;
        }
    }

    lastTimestamp = currentTimestamp;
}

/*-----------------------------------------------------------------------------------------*/
/* Function Implementations */
/*-----------------------------------------------------------------------------------------*/

/**
 * @brief Initialize Hardware Abstraction Layer for Speed ​​Sensor
 */
FUNC(void, IOHWAB_CODE) IoHwAb_SpeedSensor_Init(VAR(void, AUTOMATIC))
{
    printf("Initializing IoHwAb Speed ​​Sensor...\n");

    /* Initialize ICU Driver */
    Icu_Init();

    /* Enable interrupt when pulse from sensor */
    Icu_EnableNotification(ICU_CHANNEL_SPEED_SENSOR, IoHwAb_SpeedSensor_Callback);

    printf("IoHwAb Speed ​​Sensor Initialized.\n");
}

/**
 * @brief Reads speed from sensor via ICU
 */
FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SpeedSensor_GetSpeed(P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) speed)
{
    pulseInterval = 1U;//simulate status read speed
    if (pulseInterval > 0U)
    {
        // VAR(float, AUTOMATIC) timeSec = ((float)pulseInterval) / 1000000.0F;
        // *speed = (WHEEL_CIRCUMFERENCE * (float)PULSE_PER_REV) / timeSec;
        uint16_t random_speed = (uint16_t)(rand() % 20 + 50);
        *speed = random_speed;
        return RTE_E_OK;
    }
    else
    {
        *speed = 0;
        return RTE_E_NO_DATA;
    }
}