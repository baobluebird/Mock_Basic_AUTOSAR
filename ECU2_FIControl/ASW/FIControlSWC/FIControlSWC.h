#ifndef FICONTROL_SWC_H
#define FICONTROL_SWC_H

#include "Compiler.h"
#include "Std_ReturnType.h"

#define FICONTROL_VALVE_OFF 0U
#define FICONTROL_VALVE_ON  1U

extern VAR(uint16, AUTOMATIC) VehicleSpeed;

extern VAR(uint16, AUTOMATIC) SpeedThreshold;

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCalibData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ReadCANData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_CompareSpeedAndThreshold(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState);

#endif /* FICONTROL_SWC_H */