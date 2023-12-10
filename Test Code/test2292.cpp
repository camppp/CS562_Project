#include <stdint.h>

#ifdef __AVR__
#include <avr/pgmspace.h>
#endif

uint8_t readFromProgramMemory(const uint8_t* address) {
#ifdef __AVR__
    return pgm_read_byte(address);
#else
    return *address;
#endif
}
