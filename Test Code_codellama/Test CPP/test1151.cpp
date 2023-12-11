#include <iostream>
#include <string>

class MemberFlags {
public:
    // Constructor
    MemberFlags() {}

    // Setters
    void setOptional(bool isOptional) {
        this->isOptional = isOptional;
    }

    void setMustUnderstand(bool isMustUnderstand) {
        this->isMustUnderstand = isMustUnderstand;
    }

    void setKey(bool isKey) {
        this->isKey = isKey;
    }

    void setDefault(bool isDefault) {
        this->isDefault = isDefault;
    }

    void setDataType(const std::string& dataType) {
        this->dataType = dataType;
    }

    // Check and perform action
    void checkAndPerformAction() {
        if (dataType == "long double") {
            // Perform specific action
            std::cout << "Data type is long double" << std::endl;
        }
    }

private:
    bool isOptional;
    bool isMustUnderstand;
    bool isKey;
    bool isDefault;
    std::string dataType;
};

int main() {
    MemberFlags flags;

    // Set member flags
    flags.setOptional(true);
    flags.setMustUnderstand(true);
    flags.setKey(true);
    flags.setDefault(true);
    flags.setDataType("long double");

    // Check and perform action
    flags.checkAndPerformAction();

    return 0;
}
