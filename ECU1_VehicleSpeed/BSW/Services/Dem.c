#include "Dem.h"
#include "Rte_Dem.h"
#include "Nvm.h"
#include <stdio.h>

#define MAX_DTC_COUNT 10 // Maximum number of errors that can be stored

/* Error storage */
static uint16_t storedDTCs[MAX_DTC_COUNT] = {0};
static Dem_EventStatusType storedStatus[MAX_DTC_COUNT] = {DEM_EVENT_STATUS_PASSED};
static uint8_t dtcCount = 0;

/**
 * @brief Report errors to DEM (via RTE)
 */
FUNC(void, DEM_CODE) Dem_ReportErrorStatus(VAR(uint16_t, AUTOMATIC) DTC, VAR(Dem_EventStatusType, AUTOMATIC) status)
{
    uint8_t i;
    
    if (status == DEM_EVENT_STATUS_FAILED)
    {
        for (i = 0; i < dtcCount; i++)
        {
            if (storedDTCs[i] == DTC)
            {
                storedStatus[i] = DEM_EVENT_STATUS_FAILED;
                //printf("DEM: Error %X updated to FAILED\n", DTC);
                
                return;
            }
        }

        if (dtcCount < MAX_DTC_COUNT)
        {
            storedDTCs[dtcCount] = DTC;
            storedStatus[dtcCount] = DEM_EVENT_STATUS_FAILED;
            dtcCount++;
            //printf("DEM: Error %X reported as FAILED\n", DTC);
        }
    }
    else if (status == DEM_EVENT_STATUS_CONFIRMED)
    {
        for (i = 0; i < dtcCount; i++)
        {
            if (storedDTCs[i] == DTC)
            {
                storedStatus[i] = DEM_EVENT_STATUS_CONFIRMED;
                return;
            }
        }
    }
    else if (status == DEM_EVENT_STATUS_PASSED)
    {
        Dem_ClearDTC(DTC);
    }
}


/**
 * @brief Gets the error status of a DTC
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(VAR(uint16_t, AUTOMATIC) DTC, P2VAR(Dem_EventStatusType, AUTOMATIC, DEM_APPL_DATA) Status)
{
	  uint8_t i;
    for (i = 0; i < dtcCount; i++)
    {
        if (storedDTCs[i] == DTC)
        {
            *Status = storedStatus[i];
            return RTE_E_OK;
        }
    }
    return RTE_E_NOT_OK;
}

/**
 * @brief Remove a DTC from the list
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearDTC(VAR(uint16_t, AUTOMATIC) DTC)
{
	  uint8_t i;
    for (i = 0; i < dtcCount; i++)
    {
        if (storedDTCs[i] == DTC)
        {
            //printf("DEM: Error %X cleared\n", DTC);
            uint8_t j;
            for (j = i; j < dtcCount - 1; j++)
            {
                storedDTCs[j] = storedDTCs[j + 1];
                storedStatus[j] = storedStatus[j + 1];
            }

            dtcCount--;
            return RTE_E_OK;
        }
    }
    return RTE_E_NOT_OK;
}

/**
 * @brief Gets the list of saved DTCs
 */
FUNC(void, DEM_CODE) Dem_GetStoredDTC(P2VAR(uint16_t, AUTOMATIC, DEM_APPL_DATA) dtcList, P2VAR(uint8_t, AUTOMATIC, DEM_APPL_DATA) dtcCountOut)
{
	  uint8_t i;
    for (i = 0; i < dtcCount; i++)
    {
        dtcList[i] = storedDTCs[i];
    }
    *dtcCountOut = dtcCount;
}