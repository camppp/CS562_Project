#include <iostream>
#include <vector>

class CharacterBuffer {
public:
    CharacterBuffer(int preambleSize, int bufferSize) {
        preamble = new unsigned char[preambleSize];
        charPos = 0;
        charLen = bufferSize;
    }

    ~CharacterBuffer() {
        delete[] preamble;
    }

    char ReadChar() {
        if (charPos >= charLen) {
            return '\0';
        }

        char c = preamble[charPos];
        charPos++;
        return c;
    }

    void WriteChar(char c) {
        if (charPos < charLen) {
            preamble[charPos] = c;
            charPos++;
        }
    }

private:
    unsigned char* preamble;
    int charPos;
    int charLen;
};
