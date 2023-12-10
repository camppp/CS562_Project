#include <cstring> // For strlen, strcpy, strcat
#include <iostream>

class CustomString {
private:
    char* data; // Pointer to the dynamically allocated string data
    size_t len; // Length of the string

public:
    // Constructs an empty string.
    CustomString() : data(new char[1]), len(0) {
        data[0] = '\0';
    }

    // Constructs a string initialized with the contents of the null-terminated character array pointed to by s.
    CustomString(const char* s) : data(new char[strlen(s) + 1]), len(strlen(s)) {
        strcpy(data, s);
    }

    // Returns the length of the string.
    size_t length() const {
        return len;
    }

    // Returns the character at the specified index.
    char& operator[](size_t index) {
        return data[index];
    }

    // Concatenates the specified string to the end of this string.
    CustomString& operator+=(const CustomString& other) {
        char* temp = new char[len + other.len + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        delete[] data;
        data = temp;
        len += other.len;
        return *this;
    }

    // Compares two strings for equality.
    bool operator==(const CustomString& other) const {
        return (len == other.len) && (strcmp(data, other.data) == 0);
    }

    // Destructor to release any allocated resources.
    ~CustomString() {
        delete[] data;
    }
};

int main() {
    CustomString str1("Hello");
    CustomString str2("World");
    std::cout << "Length of str1: " << str1.length() << std::endl;
    std::cout << "Character at index 1 in str2: " << str2[1] << std::endl;
    str1 += str2;
    std::cout << "Concatenated string: " << str1[5] << std::endl;
    std::cout << "Are str1 and str2 equal? " << (str1 == str2) << std::endl;
    return 0;
}
