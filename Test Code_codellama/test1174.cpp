#include <string>
#include <unordered_map>

class properties {
public:
    // Default constructor
    properties() : namespace_(""), class_(""), instance_(""), properties_() {}

    // Parameterized constructor
    properties(const std::string& namespace_, const std::string& class_, const std::string& instance_) :
        namespace_(namespace_), class_(class_), instance_(instance_), properties_() {}

    // Add a new property
    void add_property(const std::string& key, const std::string& value) {
        properties_[key] = value;
    }

    // Retrieve the value of a property
    std::string get_property(const std::string& key) {
        return properties_.at(key);
    }

    // Update the value of an existing property
    void update_property(const std::string& key, const std::string& value) {
        properties_[key] = value;
    }

    // Remove a property
    void remove_property(const std::string& key) {
        properties_.erase(key);
    }

private:
    // Namespace, class, and instance names
    std::string namespace_;
    std::string class_;
    std::string instance_;

    // Properties container
    std::unordered_map<std::string, std::string> properties_;
};
