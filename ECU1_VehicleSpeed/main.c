#include "BSW/Services/Os.h"
#include "BSW/Services/Dem.h"
int main() {
    StartOS(); 

    uint16_t DTC;
    Dem_ReadErrorStatus(&DTC);
    printf("Tester Read DTC: %X\n", DTC);

    return 0;
}
