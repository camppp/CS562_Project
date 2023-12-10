#include <iostream>
#include <string>

class CustomString {
public:
    CustomString(const std::string& str) : str_(str) {}

    void insert(int pos, const std::string& str) {
        str_.insert(pos, str);
    }

    void print() {
        std::cout << str_ << std::endl;
    }

private:
    std::string str_;
};
