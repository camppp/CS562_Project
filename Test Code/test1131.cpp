#include <stdio.h>
#include <stdint.h>

#define kOption1ByteExtension 13

void parseCoapOptions(const uint8_t* buf, size_t bufSize) {
    size_t offset = 0;

    while (offset < bufSize) {
        uint8_t optionLength = buf[offset] & 0x0f;
        offset += sizeof(uint8_t);

        if (optionLength == 13) {
            // Handle 1-byte option length extension
            optionLength += buf[offset];
            offset += sizeof(uint8_t);
        } else if (optionLength == 14) {
            // Handle 2-byte option length extension
            optionLength += (buf[offset] << 8) + buf[offset + 1];
            offset += sizeof(uint16_t);
        }

        // Extract option delta and process further
        // ...

        // Print or store the option details
        printf("Option Length: %d\n", optionLength);
        // Print or store option delta and value extensions
        // ...

        // Move to the next option
        offset += optionLength;
    }
}
