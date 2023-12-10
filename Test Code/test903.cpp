#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <any>

class EventSystem {
public:
    void registerEventHandler(const std::string& eventType, std::function<void(const std::any&)> handlerFunction) {
        eventHandlers[eventType].push_back(handlerFunction);
    }

    void triggerEvent(const std::string& eventType, const std::any& eventData) {
        if (eventHandlers.find(eventType) != eventHandlers.end()) {
            for (const auto& handler : eventHandlers[eventType]) {
                handler(eventData);
            }
        }
    }

    void unregisterEventHandler(const std::string& eventType, std::function<void(const std::any&)> handlerFunction) {
        if (eventHandlers.find(eventType) != eventHandlers.end()) {
            auto& handlers = eventHandlers[eventType];
            handlers.erase(std::remove(handlers.begin(), handlers.end(), handlerFunction), handlers.end());
        }
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void(const std::any&)>>> eventHandlers;
};

// Example usage
void onEvent(const std::any& eventData) {
    std::cout << "Event triggered with data: " << std::any_cast<int>(eventData) << std::endl;
}

int main() {
    EventSystem eventSystem;
    eventSystem.registerEventHandler("click", onEvent);
    eventSystem.triggerEvent("click", 42);
    eventSystem.unregisterEventHandler("click", onEvent);
    return 0;
}
