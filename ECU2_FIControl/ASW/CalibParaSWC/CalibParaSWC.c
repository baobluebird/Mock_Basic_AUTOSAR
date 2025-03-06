#include "CalibParaSWC.h"
#include <stdio.h>

#define SPEED_THRESHOLD_DEFAULT 120.0f

static VAR(uint16_t, AUTOMATIC) SpeedThreshold;

FUNC(Std_ReturnType, CALIBPARA_CODE) CalibParaSWC_Init(void)
{
    SpeedThreshold = SPEED_THRESHOLD_DEFAULT;
    return RTE_E_OK;
}

FUNC(Std_ReturnType, CALIBPARA_CODE) CalibParaSWC_GetSpeedThreshold(
    P2VAR(uint16_t, AUTOMATIC, RTE_APPL_DATA) threshold)
{
    *threshold = SpeedThreshold;
    return RTE_E_OK;
}