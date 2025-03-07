#include <stdio.h>
#include <stdint.h>

#define __USE_NO_SEMIHOSTING 
#define __NO_STDIO  

FILE __stdout;

int fputc(int ch, FILE *f)
{
    return ch;
}

void _sys_exit(int return_code)
{
    while (1); 
}
