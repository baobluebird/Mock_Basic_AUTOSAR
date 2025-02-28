#ifndef RTE_SPEED_SENSOR_H
#define RTE_SPEED_SENSOR_H

#include "Std_ReturnType.h"
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/* RTE APIs Prototype Declaration                                             */
/*----------------------------------------------------------------------------*/

/* Read speed data from sensor */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_SpeedData_ReceiveSpeed(
    P2VAR(float, AUTOMATIC, RTE_APPL_DATA) speed);
#define Rte_Read_ReceiveSpeed Rte_Read_RP_SpeedData_ReceiveSpeed

/* Call the runnable of Speed ​​Sensor */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_SpeedSensorSWC_ReadSpeed(
    VAR(void, AUTOMATIC));
#define Rte_Call_ReadSpeed Rte_Call_RP_SpeedSensorSWC_ReadSpeed

#endif /* RTE_SPEED_SENSOR_H */
