c
void parseCoapOptions(const uint8_t* buf, size_t bufSize) {
    // Initialize the option details
    uint8_t optionLength = 0;
    uint8_t optionDelta = 0;
    uint8_t optionValue = 0;

    // Iterate over the options in the buffer
    for (size_t i = 0; i < bufSize; i++) {
        // Extract the option length and delta
        optionLength = buf[i] & 0xF;
        optionDelta = (buf[i] >> 4) & 0xF;

        // Extract the option value
        if (optionLength > 0) {
            optionValue = buf[i + 1];
        }

        // Print or store the option details
        printf("Option %d: length=%d, delta=%d, value=%d\n", i, optionLength, optionDelta, optionValue);
    }
}
