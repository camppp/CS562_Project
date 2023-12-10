#include <iostream>
#include <sstream>

namespace base64 {
    using size_type = std::size_t;

    const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    size_type encode(std::istream &input, std::ostream &output) {
        const int chunk_size = 3;
        const int encoded_chunk_size = 4;
        char input_chunk[chunk_size];
        char encoded_chunk[encoded_chunk_size];

        size_type input_length = 0;
        size_type output_length = 0;

        while (input.read(input_chunk, chunk_size)) {
            input_length += input.gcount();

            encoded_chunk[0] = (input_chunk[0] & 0xFC) >> 2;
            encoded_chunk[1] = ((input_chunk[0] & 0x03) << 4) + ((input_chunk[1] & 0xF0) >> 4);
            encoded_chunk[2] = ((input_chunk[1] & 0x0F) << 2) + ((input_chunk[2] & 0xC0) >> 6);
            encoded_chunk[3] = input_chunk[2] & 0x3F;

            for (int i = 0; i < encoded_chunk_size; i++) {
                output << base64_chars[encoded_chunk[i]];
                output_length++;
            }
        }

        if (input.gcount() > 0) {
            // Handle padding for remaining bytes
            int padding = chunk_size - input.gcount();
            for (int i = 0; i < padding; i++) {
                input_chunk[input.gcount() + i] = '\0';
            }

            encoded_chunk[0] = (input_chunk[0] & 0xFC) >> 2;
            encoded_chunk[1] = ((input_chunk[0] & 0x03) << 4) + ((input_chunk[1] & 0xF0) >> 4);
            encoded_chunk[2] = ((input_chunk[1] & 0x0F) << 2) + ((input_chunk[2] & 0xC0) >> 6);
            encoded_chunk[3] = input_chunk[2] & 0x3F;

            for (int i = 0; i < (chunk_size + padding); i++) {
                output << base64_chars[encoded_chunk[i]];
                output_length++;
            }

            // Add padding '=' characters
            for (int i = 0; i < padding; i++) {
                output << '=';
                output_length++;
            }
        }

        return output_length;
    }
}
