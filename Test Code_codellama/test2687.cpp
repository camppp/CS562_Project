#include <iostream>
#include <string>
#include <unordered_map>

class currency {
private:
    double num_;

public:
    currency(const char* code) {
        num_ = isonum2hash(code);
    }

    void convert(const char* target_code, double amount) {
        double target_num = isonum2hash(target_code);
        num_ = amount * target_num;
    }

    void display() {
        std::cout << "Currency: " << num_ << std::endl;
    }

    friend std::istream& operator >> (std::istream& is, currency& c) {
        std::string code;
        is >> code;
        c.num_ = isonum2hash(code);
        return is;
    }
};
