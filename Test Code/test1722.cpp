#include <queue>
#include <string>
#include <stdexcept>

class Property {
    // Define the Property class as needed
};

class EventListener {
private:
    std::queue<std::string> calls;
    std::queue<std::string> names;
    std::queue<const Property*> properties;

public:
    void registerEvent(const std::string& eventName) {
        // Add the given event name to the calls queue
        calls.push(eventName);
    }

    void registerName(const std::string& name) {
        // Add the given name to the names queue
        names.push(name);
    }

    void registerProperty(const Property* property) {
        // Add the given property to the properties queue
        properties.push(property);
    }

    void handleEvent(const std::string& expectedEvent) {
        // Handle the events in the order they were registered
        if (!calls.empty()) {
            std::string callName = calls.front();
            calls.pop();
            if (callName != expectedEvent) {
                throw std::runtime_error("Unexpected event: " + callName);
            }
        } else {
            throw std::runtime_error("No more events to handle");
        }
    }
};
