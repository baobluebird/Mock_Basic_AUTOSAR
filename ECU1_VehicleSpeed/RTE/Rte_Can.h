#ifndef RTE_CAN_H
#define RTE_CAN_H

#include "Std_ReturnType.h"

/**
 * @brief Gửi dữ liệu tốc độ từ SWC qua RTE đến CAN
 */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CANMessage(
    VAR(float, AUTOMATIC) speed
);

#endif /* RTE_CAN_H */
