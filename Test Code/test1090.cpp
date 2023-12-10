#include <iostream>
#include <vector>

class EventListener {
private:
    std::vector<void (*)()> handlers;

public:
    void registerHandler(void (*handler)()) {
        handlers.push_back(handler);
    }

    void fireEvent() {
        for (auto handler : handlers) {
            handler();
        }
    }
};

int main() {
    EventListener listener;

    // Register event handlers
    listener.registerHandler([]() { std::cout << "Event handler 1 called" << std::endl; });
    listener.registerHandler([]() { std::cout << "Event handler 2 called" << std::endl; });

    // Trigger the event
    listener.fireEvent();

    return 0;
}
