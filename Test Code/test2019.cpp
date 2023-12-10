#include <iostream>
#include <memory>
#include <string>

class LuaObject {
public:
    virtual void printType() = 0;
};

class LuaNumber : public LuaObject {
public:
    void printType() override {
        std::cout << "LuaNumber" << std::endl;
    }
};

class LuaString : public LuaObject {
public:
    void printType() override {
        std::cout << "LuaString" << std::endl;
    }
};

class LuaFactory {
public:
    std::unique_ptr<LuaObject> createObject(const std::string& objectType) {
        if (objectType == "number") {
            return std::make_unique<LuaNumber>();
        } else if (objectType == "string") {
            return std::make_unique<LuaString>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    LuaFactory factory;
    std::unique_ptr<LuaObject> numberObject = factory.createObject("number");
    if (numberObject) {
        numberObject->printType();  // Output: LuaNumber
    }

    std::unique_ptr<LuaObject> stringObject = factory.createObject("string");
    if (stringObject) {
        stringObject->printType();  // Output: LuaString
    }

    std::unique_ptr<LuaObject> invalidObject = factory.createObject("invalid");
    if (!invalidObject) {
        std::cout << "Invalid object type" << std::endl;  // Output: Invalid object type
    }

    return 0;
}
