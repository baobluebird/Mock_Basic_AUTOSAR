#ifndef FICONTROL_SWC_H
#define FICONTROL_SWC_H

#include "Compiler.h"
#include "Std_ReturnType.h"

#define FICONTROL_VALVE_OFF 0U
#define FICONTROL_VALVE_ON  1U

extern VAR(uint16, AUTOMATIC) VehicleSpeed;

extern VAR(uint16, AUTOMATIC) SpeedThreshold;

/**
* @brief Runnable: Check for errors and report errors to DEM
* @return Std_ReturnType - Execution status (RTE_E_OK or RTE_E_NOT_OK)
*/
extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_CheckAndReportError(void);

/**
* @brief Runnable: Save error to NVM if error has been acknowledged by DEM
* @return Std_ReturnType - Execution status (RTE_E_OK or RTE_E_NOT_OK)
*/
extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_SendErrorToNVBlockSWC(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ReadCalibData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ReadCANData(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_CompareSpeedAndThreshold(void);

extern FUNC(Std_ReturnType, FICONTROL_CODE) R_FIControlSWC_ControlFIValve(VAR(uint8_t, AUTOMATIC) controlState);

#endif /* FICONTROL_SWC_H */