#include <iostream>
#include <string>

// Define the enumeration for property types
enum class EPropertyType { Enum, Flags, String };

// Base class for properties
class CProperty {
public:
    virtual ~CProperty() {}
};

// Class for enumeration properties
class CEnumProperty : public CProperty {
public:
    int Value(void* pData) {
        // Implementation to retrieve the value of the enumeration property
        return *static_cast<int*>(pData);
    }
};

// Class for flags properties
class CFlagsProperty : public CProperty {
public:
    int Value(void* pData) {
        // Implementation to retrieve the value of the flags property
        return *static_cast<int*>(pData);
    }
};

// Class for string properties
class CStringProperty : public CProperty {
public:
    std::string Value(void* pData) {
        // Implementation to retrieve the value of the string property
        return *static_cast<std::string*>(pData);
    }
};

// Property serializer class
class PropertySerializer {
public:
    void SerializeProperty(EPropertyType type, CProperty* pProperty, std::ostream& rOut) {
        switch (type) {
            case EPropertyType::Enum: {
                CEnumProperty* pEnum = dynamic_cast<CEnumProperty*>(pProperty);
                if (pEnum) {
                    rOut << pEnum->Value(nullptr);
                }
                break;
            }
            case EPropertyType::Flags: {
                CFlagsProperty* pFlags = dynamic_cast<CFlagsProperty*>(pProperty);
                if (pFlags) {
                    rOut << pFlags->Value(nullptr);
                }
                break;
            }
            case EPropertyType::String: {
                CStringProperty* pString = dynamic_cast<CStringProperty*>(pProperty);
                if (pString) {
                    rOut << pString->Value(nullptr);
                }
                break;
            }
        }
    }
};

int main() {
    // Example usage of PropertySerializer
    PropertySerializer serializer;
    
    // Create and serialize an enumeration property
    CEnumProperty enumProperty;
    int enumValue = 42;
    serializer.SerializeProperty(EPropertyType::Enum, &enumProperty, std::cout);
    
    // Create and serialize a flags property
    CFlagsProperty flagsProperty;
    int flagsValue = 123;
    serializer.SerializeProperty(EPropertyType::Flags, &flagsProperty, std::cout);
    
    // Create and serialize a string property
    CStringProperty stringProperty;
    std::string stringValue = "Hello, World!";
    serializer.SerializeProperty(EPropertyType::String, &stringProperty, std::cout);
    
    return 0;
}
