void manipulateData(uint8_t* buf, int startBit, int length, uint64_t mask, uint64_t valAsBits) {
    // Reverse the order of bytes in the buffer
    uint8_t* reversedBuf = new uint8_t[8];
    for (int i = 0; i < 8; i++) {
        reversedBuf[i] = buf[7 - i];
    }

    // Extract a 64-bit integer from the reversed buffer
    uint64_t extractedValue = 0;
    for (int i = 0; i < 8; i++) {
        extractedValue |= (uint64_t)reversedBuf[i] << (8 * i);
    }

    // Apply bitwise operations to modify the extracted data
    extractedValue &= mask;
    extractedValue |= valAsBits;

    // Reverse the order of bytes in the modified buffer and store the result back in buf
    for (int i = 0; i < 8; i++) {
        buf[7 - i] = (uint8_t)(extractedValue >> (8 * i));
    }

    delete[] reversedBuf;
}
