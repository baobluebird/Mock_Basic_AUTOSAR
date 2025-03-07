#include "Flash_Driver.h"
#include <string.h>
//#define FLASH_FILE "FLASH.txt" 


static VAR(uint8, AUTOMATIC) FlashMemory[FLASH_TOTAL_SIZE] = {0};

volatile VAR(uint8, AUTOMATIC) DataSimulate[FLASH_TOTAL_SIZE] = {0};


bool Eep_Write(uint32_t address, const uint8_t *data, uint32_t length) {
    //printf("Eep_Write called at address 0x%X with length %d\n", address, length);
    return true; 
}

bool Eep_Read(uint32_t address, uint8_t *data, uint32_t length) {
    //printf("Eep_Read called at address 0x%X with length %d\n", address, length);
    return true; 
}

bool Fls_Write(uint32_t address, const uint8_t *data, uint32_t length)
{
    
    // FILE *file = fopen(FLASH_FILE, "r+b");  
	  
    // if (file == NULL)
    // {
			  
    //     file = fopen("FLASH.txt", "wb"); 
    //     if (file == NULL)
    //     {    
					  
    //         printf("Error: Cannot open FLASH.txt for writing!\n");
	// 				  fflush(stdout); 
    //         return false;
    //     }
	// 			check = 1;
    // }
    
    // fseek(file, address, SEEK_SET);  
    // size_t written = fwrite(data, 1, length, file);
	
    // fclose(file);

    // if (written != length)
    // {
    //    // printf("Error: Failed to write full data to FLASH.data!\n");
    //     return false;
    // }

    //printf("Fls_Write: Wrote %d bytes at address 0x%X\n", length, address);
    memcpy(&FlashMemory[address], data, length);
    memcpy((void *)DataSimulate, FlashMemory, FLASH_TOTAL_SIZE);
    return true;
}

bool Fls_Read(uint32_t address, uint8_t *data, uint32_t length) {
    //printf("Fls_Read called at address 0x%X with length %d\n", address, length);
    return true; 
}

void Fls_Erase(uint32_t address, uint32_t length) {
    //printf("Fls_Erase called at address 0x%X with length %d\n", address, length);
}