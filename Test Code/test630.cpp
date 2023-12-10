#include <iostream>
#include <cstring>
#include <climits>

class Str {
private:
    char *str;
    int maxlen = INT_MAX - 1;
    int len = 0;

    int countLength(char *s) {
        int length = 0;
        while (s[length] != '\0') {
            length++;
        }
        return length;
    }

public:
    Str(char *s) {
        len = countLength(s);
        if (len < maxlen) {
            str = new char[len + 1];
            strcpy(str, s);
        } else {
            std::cerr << "String length exceeds maximum allowed length." << std::endl;
            str = nullptr;
        }
    }

    ~Str() {
        delete[] str;
    }

    void printStr() {
        if (str != nullptr) {
            std::cout << str << std::endl;
        } else {
            std::cerr << "String is null." << std::endl;
        }
    }

    int length() {
        return len;
    }

    char at(int pos) {
        if (pos >= 0 && pos < len) {
            return str[pos];
        } else {
            std::cerr << "Invalid position." << std::endl;
            return '\0';
        }
    }
};

int main() {
    char input[] = "CustomString";
    Str customStr(input);
    customStr.printStr();  // Output: CustomString
    std::cout << "Length: " << customStr.length() << std::endl;  // Output: Length: 12
    std::cout << "Character at position 3: " << customStr.at(3) << std::endl;  // Output: Character at position 3: t
    return 0;
}
