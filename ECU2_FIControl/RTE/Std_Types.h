#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Basic data types */
typedef unsigned char      uint8;
typedef signed char        sint8;
typedef unsigned short     uint16;
typedef signed short       sint16;
typedef unsigned int       uint32;
typedef signed int         sint32;
typedef unsigned long long uint64;
typedef signed long long   sint64;
typedef float              float32;
typedef double             float64;

/* Standard return type (for AUTOSAR return codes) */
typedef enum
{
    E_OK = 0,               /* Operation successful */
    E_NOT_OK = 1            /* Operation failed */
} Std_ReturnType;

/* Boolean type */
typedef uint8             boolean;
#define TRUE  1
#define FALSE 0

/* NULL pointer */
#define NULL_PTR ((void*)0)

#endif /* STD_TYPES_H */
