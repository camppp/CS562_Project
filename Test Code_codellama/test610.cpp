#include <iostream>

enum Tristate { True, False, Unset };

class Tristate {
public:
    Tristate() : mValue(Unset) {}

    Tristate& operator=(bool const aValue) {
        if (aValue) {
            mValue = True;
        } else {
            mValue = False;
        }
        return *this;
    }

    // Other member functions and data members can be added as needed

private:
    Tristate mValue;
};

int main() {
    Tristate t;
    t = true;
    std::cout << "t is " << (t == True ? "True" : "False") << std::endl; // Expected output: t is True
    return 0;
}
