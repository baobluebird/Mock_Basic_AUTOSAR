#ifndef RTE_WDGM_H_
#define RTE_WDGM_H_

#include "WdgM.h"
#include "Std_ReturnType.h"
#include "Compiler.h"

extern FUNC(WdgM_StatusType, RTE_CODE) Rte_Call_WdgM_TriggerWatchdog(void);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_WdgM_SetMode(WdgIf_ModeType Mode);

#endif /* RTE_WDGM_H_ */
