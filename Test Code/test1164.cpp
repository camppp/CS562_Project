#include <iostream>
#include <string>

class CustomString {
private:
    std::string* data;
    int* refCount;

public:
    CustomString(const std::string& str) : data(new std::string(str)), refCount(new int(1)) {}

    CustomString(const CustomString& other) : data(other.data), refCount(other.refCount) {
        (*refCount)++;
    }

    CustomString& operator=(const CustomString& other) {
        if (this != &other) {
            if (--(*refCount) == 0) {
                delete data;
                delete refCount;
            }
            data = other.data;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~CustomString() {
        if (--(*refCount) == 0) {
            delete data;
            delete refCount;
        }
    }

    int refs() const {
        return *refCount;
    }
};

int main() {
    CustomString s0("Hello");
    std::cout << "#refs = " << s0.refs() << std::endl;  // Output: #refs = 1

    CustomString s1 = s0;
    std::cout << "#refs = " << s0.refs() << std::endl;  // Output: #refs = 2

    CustomString s2 = s1;
    std::cout << "#refs = " << s0.refs() << std::endl;  // Output: #refs = 3

    CustomString s3("World");
    s2 = s3;
    std::cout << "#refs = " << s0.refs() << std::endl;  // Output: #refs = 2

    return 0;
}
