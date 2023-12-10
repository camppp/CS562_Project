#include <iostream>
#include <string>

// Enumeration property type
enum class EPropertyType {
    Enum,
    Flags,
    String
};

// Enumeration property class
class CEnumProperty {
public:
    CEnumProperty(int value) : value_(value) {}
    int Value() const { return value_; }

private:
    int value_;
};

// Flags property class
class CFlagsProperty {
public:
    CFlagsProperty(int value) : value_(value) {}
    int Value() const { return value_; }

private:
    int value_;
};

// String property class
class CStringProperty {
public:
    CStringProperty(const std::string& value) : value_(value) {}
    std::string Value() const { return value_; }

private:
    std::string value_;
};

// Property serializer class
class PropertySerializer {
public:
    PropertySerializer(std::ostream& output) : output_(output) {}

    void SerializeProperty(EPropertyType type, void* property) {
        switch (type) {
            case EPropertyType::Enum:
                SerializeEnumProperty(static_cast<CEnumProperty*>(property));
                break;
            case EPropertyType::Flags:
                SerializeFlagsProperty(static_cast<CFlagsProperty*>(property));
                break;
            case EPropertyType::String:
                SerializeStringProperty(static_cast<CStringProperty*>(property));
                break;
        }
    }

private:
    void SerializeEnumProperty(CEnumProperty* property) {
        output_ << property->Value() << std::endl;
    }

    void SerializeFlagsProperty(CFlagsProperty* property) {
        output_ << property->Value() << std::endl;
    }

    void SerializeStringProperty(CStringProperty* property) {
        output_ << property->Value() << std::endl;
    }

    std::ostream& output_;
};

int main() {
    // Create a property serializer
    PropertySerializer serializer(std::cout);

    // Create an enumeration property
    CEnumProperty enumProperty(1);

    // Create a flags property
    CFlagsProperty flagsProperty(2);

    // Create a string property
    CStringProperty stringProperty("Hello, world!");

    // Serialize the properties
    serializer.SerializeProperty(EPropertyType::Enum, &enumProperty);
    serializer.SerializeProperty(EPropertyType::Flags, &flagsProperty);
    serializer.SerializeProperty(EPropertyType::String, &stringProperty);

    return 0;
}
