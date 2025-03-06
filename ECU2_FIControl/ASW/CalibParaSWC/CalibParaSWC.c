#include "CalibParaSWC.h"
#include <stdio.h>

#define SPEED_THRESHOLD_DEFAULT 200.0f

static VAR(uint16, AUTOMATIC) SpeedThreshold = SPEED_THRESHOLD_DEFAULT;

FUNC(void, CALIBPARA_CODE)
CalibParaSWC_Init(void)
{
    printf("Initializing CalibParaSWC...\n");
    SpeedThreshold = SPEED_THRESHOLD_DEFAULT;
    printf("CalibParaSWC Initialized. Speed Threshold: %.2f\n", SpeedThreshold);
}

FUNC(Std_ReturnType, CALIBPARA_CODE) CalibParaSWC_GetSpeedThreshold(
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) threshold)
{
    *threshold = SpeedThreshold;
    printf("CalibParaSWC Provided Speed Threshold: %.2f\n", *threshold);
    return RTE_E_OK;
}