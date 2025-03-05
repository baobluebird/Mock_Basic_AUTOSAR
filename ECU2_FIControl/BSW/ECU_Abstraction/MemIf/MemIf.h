// #ifndef MEMIF_H
// #define MEMIF_H

// #include "../../../Common/Std_Types.h"
// #include "../../../Common/Compiler.h"

// #define MEMIF_E_OK              (0x00U) /* Operation successful */
// #define MEMIF_E_NOT_OK          (0x01U) /* Operation failed */

// /* Memory types */
// typedef enum {
//     MEMIF_EEPROM = 0,
//     MEMIF_FLASH
// } MemIf_MemoryType;

// extern FUNC(void, MEMIF_CODE) MemIf_Init(void);

// extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(
//     VAR(MemIf_MemoryType, AUTOMATIC) memType,
//     VAR(uint32, AUTOMATIC) address,
//     P2CONST(uint8, AUTOMATIC, MEMIF_APPL_CONST) data,
//     VAR(uint32, AUTOMATIC) length
// );

// extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(
//     VAR(MemIf_MemoryType, AUTOMATIC) memType,
//     VAR(uint32, AUTOMATIC) address,
//     P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) data,
//     VAR(uint32, AUTOMATIC) length
// );

// extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Erase(
//     VAR(MemIf_MemoryType, AUTOMATIC) memType,
//     VAR(uint32, AUTOMATIC) address,
//     VAR(uint32, AUTOMATIC) length
// );

// #endif /* MEMIF_H */