class EventHandler {
public:
    // Registers a handler function for a specific event type
    void registerHandler(int eventType, void (*handlerFunction)()) {
        // Add the handler function to the map of handlers
        handlers[eventType] = handlerFunction;
    }

    // Handles an event by invoking the appropriate handler function
    bool handleEvent(int eventType) {
        // Check if a handler function is registered for the event type
        if (handlers.find(eventType) != handlers.end()) {
            // Invoke the handler function
            handlers[eventType]();
            return true;
        }
        return false;
    }

private:
    // Map of event types to handler functions
    std::map<int, void (*)()> handlers;
};
