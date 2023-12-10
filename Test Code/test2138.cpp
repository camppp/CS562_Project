#include <iostream>
#include <mutex>
#include <unordered_map>

// Define the types of configuration options
template <typename T>
class EnvOption {
public:
    EnvOption(const std::string& name, const T& default_value) : name(name), value(default_value) {}

    T get() const {
        std::lock_guard<std::mutex> lock(mutex);
        return value;
    }

    void set(const T& new_value) {
        std::lock_guard<std::mutex> lock(mutex);
        value = new_value;
    }

private:
    std::string name;
    T value;
    mutable std::mutex mutex;
};

// Thread-local configuration manager
class ConfigurationManager {
public:
    template <typename T>
    static T get(const std::string& name, const T& default_value) {
        if (options.find(name) == options.end()) {
            options[name] = new EnvOption<T>(name, default_value);
        }
        return static_cast<EnvOption<T>*>(options[name])->get();
    }

    template <typename T>
    static void set(const std::string& name, const T& value) {
        if (options.find(name) == options.end()) {
            std::cerr << "Error: Option " << name << " not found." << std::endl;
            return;
        }
        static_cast<EnvOption<T>*>(options[name])->set(value);
    }

private:
    static std::unordered_map<std::string, EnvOptionBase*> options;
};

std::unordered_map<std::string, EnvOptionBase*> ConfigurationManager::options;

// Function to set the default value for a configuration option
template <typename T>
void set_default_option(const std::string& name, const T& default_value) {
    ConfigurationManager::get<T>(name, default_value);
}

// Example usage
int main() {
    set_default_option("TRACE_EXCEPTIONS", true);
    ConfigurationManager::set("TRACE_EXCEPTIONS", false);

    std::cout << "TRACE_EXCEPTIONS: " << ConfigurationManager::get<bool>("TRACE_EXCEPTIONS", true) << std::endl;

    return 0;
}
