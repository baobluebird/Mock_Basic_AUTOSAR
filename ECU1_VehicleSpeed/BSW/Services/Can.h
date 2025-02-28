#ifndef CAN_SERVICES_H
#define CAN_SERVICES_H

#include "RTE/Std_ReturnType.h"
#include "Common/Compiler.h"

/**
 * @brief Send speed data via CAN Services
 * @param speed Speed ​​value (float)
 * @return Std_ReturnType - Status of sending data
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_Services_SendSpeed(VAR(float, AUTOMATIC) speed);

#endif /* CAN_SERVICES_H */