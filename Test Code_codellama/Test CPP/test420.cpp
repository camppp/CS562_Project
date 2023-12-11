void SetReadHandler(uint16_t startAddress, uint16_t endAddress, void (*handlerFunction)(uint16_t)) {
    // Check if the start and end addresses are valid
    if (startAddress > endAddress || startAddress < 0 || endAddress > 0xFFFF) {
        return;
    }

    // Set the read handler for the specified memory range
    for (uint16_t i = startAddress; i <= endAddress; i++) {
        M80RamRead[i] = handlerFunction;
    }
}

void SetWriteHandler(uint16_t startAddress, uint16_t endAddress, void (*handlerFunction)(uint16_t)) {
    // Check if the start and end addresses are valid
    if (startAddress > endAddress || startAddress < 0 || endAddress > 0xFFFF) {
        return;
    }

    // Set the write handler for the specified memory range
    for (uint16_t i = startAddress; i <= endAddress; i++) {
        M80RamWrite[i] = handlerFunction;
    }
}
