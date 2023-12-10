#include <iostream>
#include <cstring>

class CustomString {
private:
    char* data;

public:
    // Default constructor
    CustomString() : data(new char[1]) {
        data[0] = '\0';
    }

    // Parameterized constructor
    CustomString(const char* str) : data(new char[strlen(str) + 1]) {
        strcpy(data, str);
    }

    // Destructor
    ~CustomString() {
        delete[] data;
    }

    // Method to get the length of the string
    size_t length() const {
        return strlen(data);
    }

    // Method to append another CustomString
    void append(const CustomString& other) {
        char* temp = new char[length() + other.length() + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        delete[] data;
        data = temp;
    }

    // Method to get the C-style string representation
    const char* c_str() const {
        return data;
    }
};

int main() {
    CustomString str1; // Default constructor
    CustomString str2("Hello"); // Parameterized constructor
    CustomString str3(" World");
    
    std::cout << "Initial string: " << str1.c_str() << std::endl;
    
    str1.append(str2); // Append "Hello"
    std::cout << "After appending 'Hello': " << str1.c_str() << std::endl;
    
    str1.append(str3); // Append " World"
    std::cout << "After appending ' World': " << str1.c_str() << std::endl;
    
    std::cout << "Length of the final string: " << str1.length() << std::endl;

    return 0;
}
