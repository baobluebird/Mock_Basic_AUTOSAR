// // #include "BSW/Services/Os.h"
// #include "BSW/Services/Dem.h"
// int main() {
//     StartOS(); 

//     uint16_t DTC;
//     Dem_ReadErrorStatus(&DTC);
//     printf("Tester Read DTC: %X\n", DTC);

//     return 0;
// }

// // int main(void)
// // {
// //     NvM_Init();           // For flash/NVM stack (if used elsewhere)
// //     FI_ValveCDD_Init();   // For FI valve CDD
// //     CalibParaSWC_Init();  // For calibration parameters
// //     FIControlSWC_Init();  // For FI control logic

// //     FIControlSWC_MainFunction(); // Run once (speed = 255.0 > 200.0, valve ON)

// //     return 0;
// // }