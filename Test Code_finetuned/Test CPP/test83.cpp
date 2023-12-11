#include <iostream>

class Model {
public:
    // Default constructor
    Model() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // Copy constructor
    Model(const Model &copy) : value(copy.value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Setter and getter for value
    void setValue(int val) {
        value = val;
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

int main() {
    Model model1;
    model1.setValue(5);

    Model model2 = model1; // This will call the copy constructor
    std::cout << "Value in model2: " << model2.getValue() << std::endl;

    return 0;
}