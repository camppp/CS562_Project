#include <iostream>
#include <string>

class MemberFlags {
private:
    bool isOptional;
    bool isMustUnderstand;
    bool isKey;
    bool isDefault;
    std::string dataType;

public:
    MemberFlags() : isOptional(false), isMustUnderstand(false), isKey(false), isDefault(false), dataType("") {}

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

    void checkAndPerformAction() {
        if (dataType == "long double") {
            // Perform specific action for "long double" data type
            std::cout << "Performing specific action for long double data type" << std::endl;
        } else {
            std::cout << "No specific action for data type: " << dataType << std::endl;
        }
    }
};

int main() {
    MemberFlags member;
    member.setOptional(false);
    member.setMustUnderstand(true);
    member.setKey(true);
    member.setDefault(false);
    member.setDataType("uint32_t");
    member.checkAndPerformAction();

    member.setDataType("long double");
    member.checkAndPerformAction();

    return 0;
}
