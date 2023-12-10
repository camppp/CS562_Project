class MyReceiver {
public:
    MyReceiver() : calls(0) {}

    // Subscribe an event handler to a specific event
    void subscribe(EventType event, std::function<void(EventType)> handler) {
        // Add the handler to the list of handlers for the event
        handlers[event].push_back(handler);
    }

    // Unsubscribe an event handler from a specific event
    void unsubscribe(EventType event, std::function<void(EventType)> handler) {
        // Remove the handler from the list of handlers for the event
        handlers[event].erase(std::remove(handlers[event].begin(), handlers[event].end(), handler), handlers[event].end());
    }

    // Dispatch an event to the appropriate event handlers
    void dispatch(EventType event) {
        // Get the list of handlers for the event
        auto& handlers = this->handlers[event];

        // Iterate over the handlers and call them with the event
        for (auto& handler : handlers) {
            handler(event);
        }
    }

    // Increment the counter for the number of calls to mySlot
    void mySlot(EventType event) {
        calls++;
    }

    // Delete the object
    void selfDelete() {
        delete this;
    }

private:
    // Map of event types to lists of handlers
    std::map<EventType, std::vector<std::function<void(EventType)>>> handlers;

    // Counter for the number of calls to mySlot
    int calls;
};
