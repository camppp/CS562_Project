#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

// Define the AuxDataContainer class
class AuxDataContainer {
public:
    // Define a type for the auxiliary data
    template <typename T>
    struct AuxDataType {
        static const std::string name;  // Static member to hold the name of the type
    };

    // Define a static unordered map to store the registered types
    static std::unordered_map<std::string, const std::type_info*> registeredTypes;

    // Method to register auxiliary data types
    template <typename T>
    static void registerAuxDataType() {
        const std::type_info* typeInfo = &typeid(T);
        const std::string& typeName = AuxDataType<T>::name;

        // Check if the type with the same name is already registered
        auto it = registeredTypes.find(typeName);
        if (it != registeredTypes.end()) {
            // If the type with the same name is already registered, check if the types are compatible
            if (it->second != typeInfo) {
                // If the types are incompatible, trigger an assertion failure
                assert(false && "Different types registered for the same AuxData name.");
            }
        } else {
            // If the type with the same name is not registered, add it to the map
            registeredTypes[typeName] = typeInfo;
        }
    }
};

// Initialize the static unordered map for registered types
std::unordered_map<std::string, const std::type_info*> AuxDataContainer::registeredTypes;

// Define the static member to hold the name of the type
template <typename T>
const std::string AuxDataContainer::AuxDataType<T>::name = typeid(T).name();

int main() {
    // Register auxiliary data types
    AuxDataContainer::registerAuxDataType<int>();  // Register an int type
    AuxDataContainer::registerAuxDataType<double>();  // Register a double type

    // Attempt to register a duplicate name with a different type (should trigger an assertion failure)
    AuxDataContainer::registerAuxDataType<int>();  // Attempt to register int type again (should trigger assertion failure)

    return 0;
}
