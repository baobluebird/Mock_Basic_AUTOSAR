#include "MemIf.h"
#include "MCAL/FlashDriver/Flash.h"
#include <stdio.h>

FUNC(void, MEMIF_CODE) MemIf_Init(void)
{
    printf("Initializing MemIf...\n");
    FlashDrv_Init();
    printf("MemIf Initialized.\n");
}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    Std_ReturnType status;
    status = FlashDrv_Write(address, data, length);
    if (status == RTE_E_OK)
    {
        printf("MemIf Write Successful - Address: 0x%X, Length: %d\n", address, length);
    }
    else
    {
        printf("MemIf Write Failed\n");
    }
    return status;
}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(
    VAR(uint32, AUTOMATIC) address,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data,
    VAR(uint32, AUTOMATIC) length)
{
    Std_ReturnType status;
    status = FlashDrv_Read(address, data, length);
    if (status == RTE_E_OK)
    {
        printf("MemIf Read Successful - Address: 0x%X, Length: %d\n", address, length);
    }
    else
    {
        printf("MemIf Read Failed\n");
    }
    return status;
}