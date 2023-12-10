#include <iostream>
#include <cstring>

namespace PCMAudio {
    class Wave {
    private:
        int* audioBuffer;
        int bufferLength;

    public:
        Wave(int* buffer, int length) {
            bufferLength = length;
            audioBuffer = new int[length];
            std::memcpy(audioBuffer, buffer, length * sizeof(int));
        }

        ~Wave() {
            delete[] audioBuffer;
        }
    };
}

int main() {
    // Example usage
    int bufferA[] = {1, 2, 3, 4, 5};
    int bufferALength = 5;
    PCMAudio::Wave *wav = new PCMAudio::Wave(bufferA, bufferALength);

    // Clean up
    delete wav;

    return 0;
}
