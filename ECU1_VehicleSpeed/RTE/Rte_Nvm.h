#ifndef RTE_NVM_H
#define RTE_NVM_H

#include "Std_ReturnType.h"
#include "Compiler.h"

/** @brief RTE Write the service to write DTC to NVM */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvmInterface_WriteDTC(uint16_t dtc);

/** @brief RTE Write sends DTC from SpeedSensorSWC to NVBlockSWC */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVDATA_DTC(uint16_t dtc);

/**@brief RTE Call R_NVBlockSWC_StoreDTCToNVM to stored DTC */
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NVBlockSWC_StoreDTCToNVM(void);
#endif /* RTE_NVM_H */
// 