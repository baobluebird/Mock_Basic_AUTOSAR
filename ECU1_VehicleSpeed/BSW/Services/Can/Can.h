#ifndef CAN_SERVICES_H
#define CAN_SERVICES_H

#include "Std_ReturnType.h"
#include "Compiler.h"

/**
 * @brief Send speed data via CAN Services
 * @param speed Speed ​​value (float)
 * @return Std_ReturnType - Status of sending data
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_Services_SendSpeed(VAR(uint16_t, AUTOMATIC) speed);

#endif /* CAN_SERVICES_H */