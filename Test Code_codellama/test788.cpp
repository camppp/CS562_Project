#include <string>
#include <unordered_map>
#include <memory>

enum class property_id : uint32_t {
    ENUM_SIZE
    // Other property IDs can be added here
};

class property_value_base {
    // Base class for property values
};

class property_value : public property_value_base {
public:
    property_value(std::string&& value) : value_(std::move(value)) {
        // Implementation details
    }
private:
    std::string value_;
};

class property_manager {
public:
    // Returns the property ID for the given property name
    uint32_t get_property_id(const std::string& name) {
        // Check if the property name is already in the map
        auto it = property_name_to_id_.find(name);
        if (it != property_name_to_id_.end()) {
            return it->second;
        }

        // If the property name is not found, return the value of ENUM_SIZE
        return property_id::ENUM_SIZE;
    }

    // Creates and returns a unique pointer to a property_value_base object
    std::unique_ptr<property_value_base> create_property_value(uint32_t id, std::string&& value) {
        // Check if the property ID is valid
        if (id >= property_id::ENUM_SIZE) {
            return nullptr;
        }

        // Create a new property value object
        auto pv = std::make_unique<property_value>(std::move(value));

        // Return the unique pointer to the property value object
        return pv;
    }

private:
    std::unordered_map<std::string, uint32_t> property_name_to_id_;
};
