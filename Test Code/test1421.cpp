void readRegister(int memoryBank, int memoryAddress, int* output) {
    // Perform read operation from the specified memory bank and address
    // and store the data in the output array
    // Pseudocode: output = memory[memoryBank][memoryAddress]
    *output = memory[memoryBank][memoryAddress];
}

void writeRegister(int memoryBank, int memoryAddress, int data) {
    // Perform write operation to the specified memory bank and address
    // with the data from the bitData register
    // Pseudocode: memory[memoryBank][memoryAddress] = data
    memory[memoryBank][memoryAddress] = data;
}
