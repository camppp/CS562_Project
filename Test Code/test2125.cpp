#include <iostream>
#include <cstring>

class CustomString {
private:
    char* data;
    size_t length;

public:
    CustomString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    CustomString operator+(const char* suffix) {
        size_t newLength = length + strlen(suffix);
        char* newData = new char[newLength + 1];
        strcpy(newData, data);
        strcat(newData, suffix);
        return CustomString(newData);
    }

    size_t getLength() const {
        return length;
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomString& str) {
        os << str.data;
        return os;
    }

    ~CustomString() {
        delete[] data;
    }
};

int main() {
    CustomString list("custom ");
    list = list + "object";
    std::cout << list << std::endl;
    std::cout << "New length of string: " << list.getLength() << std::endl;
    return 0;
}
