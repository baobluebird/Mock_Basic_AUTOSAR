#include "BSW/Services/Os.h"
#include "BSW/Services/Dem.h"
int main() {
    Os_Init();  
    Os_Start(); 

    uint16_t DTC;
    Dem_ReadErrorStatus(&DTC);
    printf("Tester Read DTC: %X\n", DTC);

    return 0;
}
