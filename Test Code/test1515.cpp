#include <iostream>

class CSample {
private:
    int value;

public:
    CSample() : value(0) {}

    void set(int a) {
        value = a;
    }

    int get() {
        return value;
    }

    std::string judging() {
        if (value < 10) {
            return "Low";
        } else if (value < 20) {
            return "Medium";
        } else {
            return "High";
        }
    }
};

int main() {
    CSample obj;
    int a;
    while (1) {
        std::cin >> a;
        obj.set(a);
        std::cout << "input:" << obj.get() << std::endl;
        std::cout << obj.judging() << std::endl;
    }
    return 0;
}
