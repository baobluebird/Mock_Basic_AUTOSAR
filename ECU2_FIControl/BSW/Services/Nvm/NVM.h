#ifndef NVM_H
#define NVM_H

#include "../../../Common/Compiler.h"
#include "../../../RTE/Std_ReturnType.h"

#define NVM_BLOCK_ID_1 1U
#define NVM_BLOCK_SIZE 4U

extern FUNC(void, NVM_CODE) NvM_Init(void);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_Write(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_Read(
    VAR(uint16, AUTOMATIC) blockId,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data
);

#endif 
/*
int main(void)
{
    uint8 dataWrite[4] = {0x12, 0x34, 0x56, 0x78};
    uint8 dataRead[4] = {0};

    NvM_Init();
    NvM_Write(NVM_BLOCK_ID_1, dataWrite);
    NvM_Read(NVM_BLOCK_ID_1, dataRead);

    printf("Read Data: %02X %02X %02X %02X\n", dataRead[0], dataRead[1], dataRead[2], dataRead[3]);
    return 0;
}
*/

// void NVBlockSWC_Function(void)
// {
//     uint8 dataWrite[4] = {0x12, 0x34, 0x56, 0x78};
//     uint8 dataRead[4] = {0};
//     Std_ReturnType status;

//     status = Rte_Write_NVBlock_Data(NVM_BLOCK_ID_1, dataWrite);
//     if (status == RTE_E_OK)
//     {
//         printf("SWC Wrote NV Data\n");
//     }

//     status = Rte_Read_NVBlock_Data(NVM_BLOCK_ID_1, dataRead);
//     if (status == RTE_E_OK)
//     {
//         printf("SWC Read NV Data: %02X %02X %02X %02X\n", 
//                dataRead[0], dataRead[1], dataRead[2], dataRead[3]);
//     }
// }
