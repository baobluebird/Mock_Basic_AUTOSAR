// #ifndef FLASH_H
// #define FLASH_H

// #include "../../../Common/Std_Types.h"
// #include "../../../Common/Compiler.h"

// /* Error codes */
// #define FLASH_E_OK              (0x00U) /* Operation successful */
// #define FLASH_E_NOT_OK          (0x01U) /* Operation failed */
// #define FLASH_E_PARAM_ADDRESS   (0x02U) /* Invalid address */
// #define FLASH_E_PARAM_LENGTH    (0x03U) /* Invalid length */
// #define FLASH_E_BUSY            (0x04U) /* Flash is busy */

// /* Address and length types for flash memory operations */
// typedef uint32 Fls_AddressType;  /* Address type for flash memory */
// typedef uint32 Fls_LengthType;   /* Length type for flash operations */

// /* Function Prototypes */
// extern FUNC(Std_ReturnType, FLASH_CODE) Fls_Write(
//     VAR(Fls_AddressType, AUTOMATIC) TargetAddress,
//     P2CONST(uint8, AUTOMATIC, FLASH_APPL_CONST) SourceAddressPtr,
//     VAR(Fls_LengthType, AUTOMATIC) Length
// );

// extern FUNC(Std_ReturnType, FLASH_CODE) Fls_Read(
//     VAR(Fls_AddressType, AUTOMATIC) SourceAddress,
//     P2VAR(uint8, AUTOMATIC, FLASH_APPL_DATA) TargetAddressPtr,
//     VAR(Fls_LengthType, AUTOMATIC) Length
// );

// extern FUNC(Std_ReturnType, FLASH_CODE) Fls_Erase(
//     VAR(Fls_AddressType, AUTOMATIC) TargetAddress,
//     VAR(Fls_LengthType, AUTOMATIC) Length
// );

// #endif /* FLASH_H */
