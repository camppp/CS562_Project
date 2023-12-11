#include <iostream>
#include <vector>

class EventListener {
public:
    void registerHandler(void (*handler)()) {
        handlers.push_back(handler);
    }

    void fireEvent() {
        for (auto handler : handlers) {
            handler();
        }
    }

private:
    std::vector<void (*)()> handlers;
};
