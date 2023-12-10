#include <cstddef>
#include <cstring>

namespace PCMAudio {
    class Wave {
    public:
        Wave(const char* buffer, size_t length) {
            // Allocate memory for the audio data
            data = new char[length];
            // Copy the buffer to the allocated memory
            memcpy(data, buffer, length);
            // Store the length of the buffer
            this->length = length;
        }

        ~Wave() {
            // Free the allocated memory
            delete[] data;
        }

        // Getters and setters for the audio data
        const char* getData() const {
            return data;
        }

        size_t getLength() const {
            return length;
        }

    private:
        char* data;
        size_t length;
    };
}
