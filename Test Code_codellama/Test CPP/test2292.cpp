c
#include <avr/pgmspace.h>

uint8_t readFromProgramMemory(const uint8_t* address)
{
    #ifdef AVR_PGMSPACE_H
        return pgm_read_byte(address);
    #else
        return *address;
    #endif
}
