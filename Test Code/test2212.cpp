c
uint8_t readSingleByteRegister(uint8_t deviceAddress, uint8_t registerAddress) {
    uint8_t data;
    uint8_t result = readRegister(deviceAddress, registerAddress, &data, 1);
    if (result != AKHILAFLEX_OK) {
        return result;
    }
    return data;
}
