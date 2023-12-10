#include <iostream>

// Define the VM class
class VM {
public:
    int value;

    // Constructor
    VM(int val) : value(val) {}
};

// Define the UnstableNode class within the mozart namespace
namespace mozart {
    class UnstableNode {
    public:
        // Constructor taking a VM object by reference
        UnstableNode(const VM& vm) {
            // Calculate the absolute value and store it
            absoluteValue = abs(vm.value);
        }

        // Method to get the absolute value
        int getAbsoluteValue() const {
            return absoluteValue;
        }

    private:
        int absoluteValue;
    };
}

int main() {
    // Create a VM object with a negative value
    VM vm(-5);

    // Create an UnstableNode object using the VM object
    mozart::UnstableNode node(vm);

    // Get and print the absolute value
    std::cout << "Absolute value: " << node.getAbsoluteValue() << std::endl;

    return 0;
}
