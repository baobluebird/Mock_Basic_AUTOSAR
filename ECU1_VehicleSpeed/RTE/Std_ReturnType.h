#ifndef STD_RETURNTYPE_H
#define STD_RETURNTYPE_H

#include "Std_Types.h" 

/** @brief AUTOSAR standard return data type */
typedef uint8 Std_ReturnType;

/** @brief Success value */
#define RTE_E_OK (0x00U)

/** @brief Error when no valid data */
#define RTE_E_NO_DATA (0x01U)

/** @brief Transmission failure error */
#define RTE_E_TRANSMIT_FAILED (0x02U)

/** @brief Invalid input data error */
#define RTE_E_INVALID (0x03U)

/** @brief Response timeout */
#define RTE_E_TIMEOUT (0x04U)

/** @brief Resource limit reached (full queue, full buffer, etc.) */
#define RTE_E_LIMIT (0x05U)

/** @brief Port not connected error */
#define RTE_E_UNCONNECTED (0x06U)

/** @brief Unknown general error */
#define RTE_E_GENERAL_ERROR (0xFFU)

#endif 