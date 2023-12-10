#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

class EventSystem {
public:
    void registerEventHandler(const std::string& eventType, std::function<void(const std::any&)> handlerFunction) {
        eventHandlers[eventType].push_back(handlerFunction);
    }

    void triggerEvent(const std::string& eventType, const std::any& eventData) {
        for (const auto& handler : eventHandlers[eventType]) {
            handler(eventData);
        }
    }

    void unregisterEventHandler(const std::string& eventType, std::function<void(const std::any&)> handlerFunction) {
        auto it = std::find(eventHandlers[eventType].begin(), eventHandlers[eventType].end(), handlerFunction);
        if (it != eventHandlers[eventType].end()) {
            eventHandlers[eventType].erase(it);
        }
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void(const std::any&)>>> eventHandlers;
};
