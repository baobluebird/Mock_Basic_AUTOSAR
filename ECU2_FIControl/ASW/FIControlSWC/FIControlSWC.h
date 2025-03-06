#ifndef FICONTROL_SWC_H
#define FICONTROL_SWC_H

#include "Common/Compiler.h"
#include "RTE/Std_ReturnType.h"

extern VAR(uint16, AUTOMATIC) VehicleSpeed;

extern VAR(uint16, AUTOMATIC) SpeedThreshold;

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_Init(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCalibData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCANData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ControlFIValve(void);

#endif /* FICONTROL_SWC_H */