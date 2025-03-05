// #include "Flash.h"
// #include <string.h>  // For memcpy

// /* Simulated Flash memory */
// static uint8_t FlashMemory[FLASH_TOTAL_SIZE];

// /* Erase Flash memory pages */
// FUNC(Std_ReturnType, FLASH_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
// {
//     /* Check if the address and length are within bounds */
//     if (TargetAddress < FLASH_START_ADDRESS || (TargetAddress + Length) > (FLASH_START_ADDRESS + FLASH_TOTAL_SIZE)) {
//         return FLASH_E_NOT_OK;
//     }

//     /* Simulate erasing by setting memory to 0xFF */
//     memset(&FlashMemory[TargetAddress - FLASH_START_ADDRESS], 0xFF, Length);
//     return FLASH_E_OK;
// }

// /* Read data from Flash memory */
// FUNC(Std_ReturnType, FLASH_CODE) Fls_Read(Fls_AddressType SourceAddress, uint8* TargetAddressPtr, Fls_LengthType Length)
// {
//     /* Check if the address and length are within bounds */
//     if (SourceAddress < FLASH_START_ADDRESS || (SourceAddress + Length) > (FLASH_START_ADDRESS + FLASH_TOTAL_SIZE)) {
//         return FLASH_E_NOT_OK;
//     }

//     /* Simulate reading from flash memory */
//     memcpy(TargetAddressPtr, &FlashMemory[SourceAddress - FLASH_START_ADDRESS], Length);
//     return FLASH_E_OK;
// }

// /* Write data to Flash memory */
// FUNC(Std_ReturnType, FLASH_CODE) Fls_Write(Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, Fls_LengthType Length)
// {
//     /* Check if the address and length are within bounds */
//     if (TargetAddress < FLASH_START_ADDRESS || (TargetAddress + Length) > (FLASH_START_ADDRESS + FLASH_TOTAL_SIZE)) {
//         return FLASH_E_NOT_OK;
//     }

//     /* Simulate writing to flash memory */
//     memcpy(&FlashMemory[TargetAddress - FLASH_START_ADDRESS], SourceAddressPtr, Length);
//     return FLASH_E_OK;
// }
