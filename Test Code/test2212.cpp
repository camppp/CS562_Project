#include <stdint.h>

#define AKHILAFLEX_OK 0

// Given function to read from a hardware device
int readRegister(uint8_t address, uint8_t reg, uint8_t *data, uint8_t numBytes);

uint8_t readSingleByteRegister(uint8_t deviceAddress, uint8_t registerAddress) {
    uint8_t data;
    int result = readRegister(deviceAddress, registerAddress, &data, 1);
    
    return (result == AKHILAFLEX_OK) ? data : (uint8_t)result;
}
