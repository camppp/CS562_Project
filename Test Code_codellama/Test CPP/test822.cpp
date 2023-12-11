class EventSubscriptionManager {
private:
    // Map of event subscriptions, where the key is the event name and the value is a set of subscribers
    std::map<std::string, std::set<std::string>> subscriptions;

    // Map of event forwarders, where the key is the event name and the value is a set of forwarders
    std::map<std::string, std::set<std::string>> forwarders;

public:
    // Add a new subscription
    void addSubscription(const std::string& eventName, const std::string& subscriber) {
        subscriptions[eventName].insert(subscriber);
    }

    // Update an existing subscription
    void updateSubscription(const std::string& eventName, const std::string& subscriber) {
        subscriptions[eventName].erase(subscriber);
        subscriptions[eventName].insert(subscriber);
    }

    // Delete a subscription
    void deleteSubscription(const std::string& eventName, const std::string& subscriber) {
        subscriptions[eventName].erase(subscriber);
    }

    // Forward an event to the appropriate subscribers
    void forwardEvent(const std::string& eventName, const std::string& eventData) {
        auto subscribers = subscriptions[eventName];
        for (const auto& subscriber : subscribers) {
            forwarders[eventName].insert(subscriber);
        }
    }

    // Remove a forwarder
    void removeForwarder(const std::string& eventName, const std::string& forwarder) {
        forwarders[eventName].erase(forwarder);
    }
};
