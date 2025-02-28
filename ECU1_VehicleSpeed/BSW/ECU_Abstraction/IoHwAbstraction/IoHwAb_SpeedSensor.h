#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include "RTE/Std_ReturnType.h"
#include "MCAL/ICUDriver/Icu_Driver.h"

/*---------------------------------------------------------------------------------------------*/
/* Macro Definitions */
/*------------------------------------------------------------------------------------------*/

/** @brief Wheel Circumference (meters) */
#define WHEEL_CIRCUMFERENCE 2.0F

/** @brief Pulses per revolution */
#define PULSE_PER_REV 20U

/*-----------------------------------------------------------------------------*/
/* Function Prototypes */
/*-----------------------------------------------------------------------------*/

/**
 * @brief Initialize Hardware Abstraction Layer for speed sensor
 */
extern FUNC(void, IOHWAB_CODE) IoHwAb_SpeedSensor_Init(VAR(void, AUTOMATIC));

/**
 * @brief Read speed data from the sensor via ICU
 * @param speed Pointer to store the measured speed value
 * @return Std_ReturnType - Data reading status
 */
extern FUNC(Std_ReturnType, IOHWAB_CODE) IoHwAb_SpeedSensor_GetSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed);

#endif /* IOHWAB_SPEEDSENSOR_H */