#include <iostream>
#include <cstdint>

class CharacterBuffer {
private:
    uint8_t* preamble;
    int charPos;
    int charLen;

public:
    CharacterBuffer(int bufferSize) {
        preamble = new uint8_t[bufferSize];
        charPos = 0;
        charLen = bufferSize;
    }

    ~CharacterBuffer() {
        delete[] preamble;
    }

    char ReadChar() {
        if (charPos < charLen) {
            return static_cast<char>(preamble[charPos++]);
        }
        return '\0';
    }

    void WriteChar(char c) {
        if (charPos < charLen) {
            preamble[charPos++] = static_cast<uint8_t>(c);
        }
    }
};

int main() {
    CharacterBuffer buffer(10);
    buffer.WriteChar('H');
    buffer.WriteChar('i');
    buffer.WriteChar('!');
    
    std::cout << buffer.ReadChar();  // Output: 'H'
    std::cout << buffer.ReadChar();  // Output: 'i'
    std::cout << buffer.ReadChar();  // Output: '!'
    std::cout << buffer.ReadChar();  // Output: '\0' (end of buffer)
    
    return 0;
}
