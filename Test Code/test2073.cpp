#include <cstring>
#include <string>

class StringBuilder 
{
private:
    char* buffer;
    size_t length;
    size_t capacity;

public:
    StringBuilder(const char* s) {
        length = strlen(s);
        capacity = length + 1;  // +1 for null terminator
        buffer = new char[capacity];
        strcpy(buffer, s);
    }

    ~StringBuilder() {
        delete[] buffer;
    }

    void append(const char* s) {
        size_t newLength = length + strlen(s);
        if (newLength + 1 > capacity) {
            capacity = newLength + 1;
            char* newBuffer = new char[capacity];
            strcpy(newBuffer, buffer);
            strcat(newBuffer, s);
            delete[] buffer;
            buffer = newBuffer;
        } else {
            strcat(buffer, s);
        }
        length = newLength;
    }

    void append(char ch) {
        if (length + 1 < capacity) {
            buffer[length] = ch;
            buffer[length + 1] = '\0';
            length++;
        } else {
            capacity *= 2;
            char* newBuffer = new char[capacity];
            strcpy(newBuffer, buffer);
            newBuffer[length] = ch;
            newBuffer[length + 1] = '\0';
            delete[] buffer;
            buffer = newBuffer;
            length++;
        }
    }

    std::string toString() {
        return std::string(buffer);
    }
};
