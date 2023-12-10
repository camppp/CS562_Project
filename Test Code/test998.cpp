#include <iostream>
#include <cstring>

class CustomString {
private:
    char* str;
public:
    // Constructor
    CustomString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~CustomString() {
        delete[] str;
    }

    // Method to return the length of the string
    int length() {
        return strlen(str);
    }

    // Method to concatenate two strings
    void concatenate(const char* s) {
        char* temp = new char[strlen(str) + strlen(s) + 1];
        strcpy(temp, str);
        strcat(temp, s);
        delete[] str;
        str = temp;
    }

    // Method to return a substring of the string
    char* substring(int start, int len) {
        char* sub = new char[len + 1];
        strncpy(sub, &str[start], len);
        sub[len] = '\0';
        return sub;
    }
};

int main() {
    CustomString myString("Hello");
    std::cout << "Length: " << myString.length() << std::endl;

    myString.concatenate(" World!");
    std::cout << "Concatenated String: " << myString.substring(0, myString.length()) << std::endl;

    char* sub = myString.substring(6, 5);
    std::cout << "Substring: " << sub << std::endl;
    delete[] sub;

    return 0;
}
