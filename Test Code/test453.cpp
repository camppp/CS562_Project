#include <iostream>
#include <vector>
#include <string>

// Define the StructuredElement class
class StructuredElement {
private:
    std::string textField;

public:
    void setTextField(const std::string& text) {
        textField = text;
    }

    std::string getTextField() const {
        return textField;
    }
};

// Define the StructuredList class
class StructuredList {
private:
    std::vector<StructuredElement> elements;

public:
    StructuredList(int size) : elements(size) {}

    StructuredElement& operator[](int index) {
        return elements[index];
    }
};

int main() {
    StructuredList list(3);
    list[0].setTextField("structlist 1");
    list[1].setTextField("structlist 2");
    list[2].setTextField("structlist 3");

    std::cout << list[0].getTextField() << std::endl;  // Output: structlist 1
    std::cout << list[1].getTextField() << std::endl;  // Output: structlist 2
    std::cout << list[2].getTextField() << std::endl;  // Output: structlist 3

    return 0;
}
