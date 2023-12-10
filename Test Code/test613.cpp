#include <iostream>
#include <cstring>

class String {
private:
    char* original;

public:
    // Constructor from C-style string
    String(const char* str) {
        original = new char[strlen(str) + 1];
        strcpy(original, str);
    }

    // Copy constructor
    String(const String& other) {
        original = new char[strlen(other.original) + 1];
        strcpy(original, other.original);
    }

    // Assignment operator
    String& operator=(const String& target) {
        if (this != &target) {
            delete[] original;
            original = new char[strlen(target.original) + 1];
            strcpy(original, target.original);
        }
        return *this;
    }

    // Concatenation operator
    String operator+(const String& other) const {
        char* newStr = new char[strlen(original) + strlen(other.original) + 1];
        strcpy(newStr, original);
        strcat(newStr, other.original);
        String result(newStr);
        delete[] newStr;
        return result;
    }

    // Comparison operators
    bool operator==(const String& other) const {
        return strcmp(original, other.original) == 0;
    }

    bool operator!=(const String& other) const {
        return strcmp(original, other.original) != 0;
    }

    // Indexing operator
    char& operator[](size_t index) {
        return original[index];
    }

    // Destructor
    ~String() {
        delete[] original;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
    std::cout << "s3[0]: " << s3[0] << std::endl;
    return 0;
}
