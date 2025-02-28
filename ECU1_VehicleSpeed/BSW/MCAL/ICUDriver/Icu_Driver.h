#ifndef ICU_H
#define ICU_H

#include "Std_ReturnType.h"
#include "Common/Compiler.h"

/*--------------------------------------------------------------------------------------------*/
/* ICU Channel Definitions */
/*-------------------------------------------------------------------------------*/

/** @brief Speed ​​sensor channel */
#define ICU_CHANNEL_SPEED_SENSOR 0U

/*-------------------------------------------------------------------------------*/
/* Type Definitions */
/*-------------------------------------------------------------------------------*/

/** @brief Pointer to Callback function for ICU */
typedef P2FUNC(void, ICU_APPL_CODE, Icu_CallbackType)(void);

/*-----------------------------------------------------------------------------------------*/
/* Function Prototypes */
/*-----------------------------------------------------------------------------------------*/

/**
 * @brief Initialize ICU Driver
 */
extern FUNC(void, ICU_CODE) Icu_Init(VAR(void, AUTOMATIC));

/**
 * @brief Configure ICU for specific channel
 * @param channel ICU channel
 * @param callback Callback function pointer
 */
extern FUNC(void, ICU_CODE) Icu_Setup(VAR(uint8, AUTOMATIC) channel, VAR(Icu_CallbackType, AUTOMATIC) callback);

/**
 * @brief Get the time value of the ICU channel
 * @param channel ICU channel
 * @return uint32 Time value
 */
extern FUNC(uint32, ICU_CODE) Icu_GetTime(VAR(uint8, AUTOMATIC) channel);

/**
 * @brief Enable interrupt notification for the ICU channel
 * @param channel ICU channel
 * @param callback Callback function pointer
 */
extern FUNC(void, ICU_CODE) Icu_EnableNotification(VAR(uint8, AUTOMATIC) channel, VAR(Icu_CallbackType, AUTOMATIC) callback);

#endif /* ICU_H */