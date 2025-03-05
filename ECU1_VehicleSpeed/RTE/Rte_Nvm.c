#include "Rte_Nvm.h"
#include "NVBlockSWC.h"
#include "Nvm.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvmInterface_WriteDTC(uint16_t DTC)
{
    return Nvm_Write(DTC);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NVDATA_DTC(uint16_t DTC)
{
    return R_NVBlockSWC_ReceiveDTC(&DTC);
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NVBlockSWC_StoreDTCToNVM(void)
{
    return R_NVBlockSWC_StoreDTCToNVM();
}