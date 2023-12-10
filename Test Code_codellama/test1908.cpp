#include <iostream>
#include <cstring>

class PSS_ProcessPropertiesBP {
public:
    // Function to set the value of a property
    bool SetValue(const int propId, const char* pValue);
};

bool PSS_ProcessPropertiesBP::SetValue(const int propId, const char* pValue) {
    if (!pValue) {
        std::cout << "Error: pValue is null." << std::endl;
        return false;
    }

    // Add code here to set the value of the property identified by propId to the provided pValue
    switch (propId) {
        case 1:
            // Set the value of property 1 to the provided pValue
            std::cout << "Property 1 set to: " << pValue << std::endl;
            break;
        case 2:
            // Set the value of property 2 to the provided pValue
            std::cout << "Property 2 set to: " << pValue << std::endl;
            break;
        default:
            std::cout << "Error: Invalid property ID." << std::endl;
            return false;
    }

    return true;
}

int main() {
    PSS_ProcessPropertiesBP processProperties;
    processProperties.SetValue(1, "NewValue");
    processProperties.SetValue(2, nullptr);
    return 0;
}
