void readRegister(int memoryBank, int memoryAddress, int* output) {
    // Check if the memory bank and address are valid
    if (memoryBank < 0 || memoryBank >= NUM_MEMORY_BANKS ||
        memoryAddress < 0 || memoryAddress >= MEMORY_BANK_SIZE) {
        return;
    }

    // Read the data from the specified memory bank and address
    int data = memory[memoryBank][memoryAddress];

    // Store the data in the output array
    output[0] = data;
}

void writeRegister(int memoryBank, int memoryAddress, int data) {
    // Check if the memory bank and address are valid
    if (memoryBank < 0 || memoryBank >= NUM_MEMORY_BANKS ||
        memoryAddress < 0 || memoryAddress >= MEMORY_BANK_SIZE) {
        return;
    }

    // Write the data to the specified memory bank and address
    memory[memoryBank][memoryAddress] = data;
}
