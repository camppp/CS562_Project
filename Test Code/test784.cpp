#include <iostream>
#include <string>
#include <sstream>

class CustomString {
private:
    std::string s;

public:
    CustomString() : s("") {}

    void insert(int pos, const std::string& str) {
        s.insert(pos, str);
    }

    void print() {
        std::cout << s << std::endl;
    }
};

int main() {
    CustomString customStr;
    customStr.insert(0, "Hello, ");
    customStr.insert(6, "world!");
    customStr.print(); // Output: Hello, world!
    return 0;
}
