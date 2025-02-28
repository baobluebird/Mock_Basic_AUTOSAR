#ifndef OS_H
#define OS_H

#include "RTE/Std_ReturnType.h"
#include "Common/Compiler.h"

/*------------------------------------------------------------------------------*/
/* OS Configuration Constants */
/*------------------------------------------------------------------------------*/

/* Task ID definitions */
typedef enum
{
    Init_Task,
    Sensor_Read_Task,
    NUM_OF_TASKS /* Number of Tasks in the system */
} TaskType;

/* Event Mask definitions */
typedef uint32 EventMaskType;

/* Status Types */
#define STATUS_OK 0
#define STATUS_ERROR 1

/*------------------------------------------------------------------------------*/
/* Function Prototypes for OS API */
/*------------------------------------------------------------------------------*/

/**
 * @brief Starts the operating system
 */
extern void StartOS(void);

/**
 * @brief Activate a Task
 * @param TaskID ID of the Task to activate
 */
extern void ActivateTask(TaskType TaskID);

/**
 * @brief Terminate a running Task
 */
extern void TerminateTask(void);

/**
 * @brief Wait for an event (Task will be blocked until the event occurs)
 * @param EventMask ID of the event to wait for
 */
extern void WaitEvent(EventMaskType EventMask);

/**
 * @brief Get the current event of the Task
 * @param TaskID ID of the Task
 * @param EventMask Pointer to store the received event value
 */
extern void GetEvent(TaskType TaskID, EventMaskType *EventMask);

/**
 * @brief Delete a processed event
 * @param EventMask ID of the event to delete
 */
extern void ClearEvent(EventMaskType EventMask);

/*-------------------------------------------------------------------------------*/
/* Alarm & Counter API */
/*-------------------------------------------------------------------------------*/

/**
 * @brief Define Alarm ID
 */
typedef enum
{
    Sensor_Read_Alarm,
    NUM_OF_ALARMS
} AlarmType;

/**
 * @brief Define Counter ID
 */
typedef enum
{
    myCounter,
    NUM_OF_COUNTERS
} CounterType;

/**
 * @brief Set the time for an Alarm
 * @param AlarmID The ID of the Alarm to set
 * @param AlarmTime The time the first Alarm is triggered
 * @param CycleTime The cycle of the Alarm to be triggered (0 if not repeated)
 */
extern void SetRelAlarm(AlarmType AlarmID, uint32 AlarmTime, uint32 CycleTime);

/**
 * @brief Cancel an active Alarm
 * @param AlarmID The ID of the Alarm to be canceled
 */
extern void CancelAlarm(AlarmType AlarmID);

/* Define the DeclareTask macro */
#define DeclareTask(TaskName) void TaskName(void)

/* Define the TASK macro */
#define TASK(TaskName) void TaskName(void)

#endif /* OS_H */