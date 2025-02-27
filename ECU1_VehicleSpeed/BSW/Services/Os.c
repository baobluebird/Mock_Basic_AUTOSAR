#include "Os.h"
#include <stdio.h>

// OS Scheduler
void Os_Start(void) {
    while (1) {
        Sensor_Read_Task();
        usleep(10000);  // 10ms
    }
}

void Os_Init(void) {
    printf("OS Initialized...\n");
}

void Sensor_Read_Task(void) {
    printf("Executing Sensor_Read_Task...\n");
    Rte_Call_ReadSpeed();  
}
