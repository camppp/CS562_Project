#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int uint;

class CustomString {
private:
    char* str;
    uint len;

public:
    // Constructor
    CustomString(const char* s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    // Length method
    uint length() {
        return len;
    }

    // Concatenation method
    CustomString concatenate(const CustomString& s) {
        char* newStr = new char[len + s.len + 1];
        strcpy(newStr, str);
        strcat(newStr, s.str);
        CustomString result(newStr);
        delete[] newStr;
        return result;
    }

    // Substring method
    CustomString substring(uint start, uint length) {
        char* sub = new char[length + 1];
        strncpy(sub, &str[start], length);
        sub[length] = '\0';
        CustomString result(sub);
        delete[] sub;
        return result;
    }

    // Character Access method
    char charAt(uint index) {
        if (index < len) {
            return str[index];
        }
        return '\0';
    }

    // Destructor
    ~CustomString() {
        delete[] str;
    }
};
