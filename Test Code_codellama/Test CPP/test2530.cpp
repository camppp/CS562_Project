#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace base64 {

size_t encode(istream& in, ostream& out) {
    // Read the input stream in 3-byte chunks
    char buffer[3];
    size_t bytes_read = 0;
    while (in.read(buffer, 3)) {
        // Split each 3-byte chunk into four 6-bit chunks
        char chunk[4];
        for (int i = 0; i < 3; i++) {
            chunk[i] = buffer[i] >> 2;
            chunk[i + 1] = (buffer[i] & 0x3) << 4;
            chunk[i + 2] = (buffer[i + 1] & 0xf0) >> 4;
            chunk[i + 3] = (buffer[i + 1] & 0xf) << 2;
            chunk[i + 4] = (buffer[i + 2] & 0xc0) >> 6;
            chunk[i + 5] = buffer[i + 2] & 0x3f;
        }

        // Map each 6-bit chunk to its corresponding base64 character
        char base64_char[6];
        for (int i = 0; i < 6; i++) {
            base64_char[i] = 'A' + (chunk[i] & 0x3f);
        }

        // Write the base64-encoded chunk to the output stream
        out.write(base64_char, 6);

        // Increment the number of bytes read
        bytes_read += 3;
    }

    // Pad the remaining bytes with '=' characters
    if (bytes_read % 3 != 0) {
        out.write("=", bytes_read % 3);
    }

    // Return the size of the encoded data
    return bytes_read;
}

} // namespace base64
