#include <iostream>
#include <string>
#include <vector>

struct StructuredElement {
    std::string textField;
};

class StructuredList {
public:
    StructuredList(int size) {
        elements.resize(size);
    }

    void setTextField(int index, const std::string& text) {
        elements[index].textField = text;
    }

    std::string getTextField(int index) {
        return elements[index].textField;
    }

private:
    std::vector<StructuredElement> elements;
};
