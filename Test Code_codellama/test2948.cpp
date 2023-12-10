void convertAndStore(char* input, int digits) {
    // Check if there is enough space in the circular buffer to store the converted integer
    if (atoiBufferIndex + digits > ATOI_BUFFER_SIZE) {
        // Reset the buffer index to 0 if the buffer is full
        atoiBufferIndex = 0;
    }

    // Store the converted integer in the circular buffer starting from the current buffer index
    for (int i = 0; i < digits; i++) {
        atoiBuffer[atoiBufferIndex++] = input[i];
    }

    // Update the buffer index to the next available position in the circular buffer
    atoiBufferIndex %= ATOI_BUFFER_SIZE;
}
