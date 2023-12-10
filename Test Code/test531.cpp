#include <iostream>
#include <string>
#include <unordered_map>

enum class Type { None, Integer, Float, String, Boolean };

class TypeConverter {
public:
    static Type fromString(const std::string& input) {
        static const std::unordered_map<std::string, Type> typeMap = {
            {"None", Type::None},
            {"Integer", Type::Integer},
            {"Float", Type::Float},
            {"String", Type::String},
            {"Boolean", Type::Boolean}
        };

        auto it = typeMap.find(input);
        if (it != typeMap.end()) {
            return it->second;
        } else {
            return Type::None;
        }
    }
};

int main() {
    // Test the Type::fromString function
    std::cout << "Type from 'Blah': " << static_cast<int>(TypeConverter::fromString("Blah")) << std::endl; // Output: 0 (Type::None)
    std::cout << "Type from 'Integer': " << static_cast<int>(TypeConverter::fromString("Integer")) << std::endl; // Output: 1 (Type::Integer)
    std::cout << "Type from 'Float': " << static_cast<int>(TypeConverter::fromString("Float")) << std::endl; // Output: 2 (Type::Float)
    std::cout << "Type from 'String': " << static_cast<int>(TypeConverter::fromString("String")) << std::endl; // Output: 3 (Type::String)
    std::cout << "Type from 'Boolean': " << static_cast<int>(TypeConverter::fromString("Boolean")) << std::endl; // Output: 4 (Type::Boolean)

    return 0;
}
