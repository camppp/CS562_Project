#include <iostream>
#include <functional>
#include <vector>

class Signal {
public:
    using SlotFunction = std::function<void()>;

    void connect(void* object, void (*slotFunction)(), void (*callbackFunction)()) {
        connectedSlots.push_back({object, slotFunction, callbackFunction});
    }

    void emitSignal() {
        for (const auto& slot : connectedSlots) {
            void (*slotFunction)() = slot.slotFunction;
            slotFunction(); // Invoke the slot function
            void (*callbackFunction)() = slot.callbackFunction;
            callbackFunction(); // Invoke the callback function
        }
    }

private:
    struct SlotConnection {
        void* object;
        void (*slotFunction)();
        void (*callbackFunction)();
    };

    std::vector<SlotConnection> connectedSlots;
};

// Example usage
class Core {
public:
    static Core* getInstance() {
        static Core instance;
        return &instance;
    }

    void onFriendStatusChanged() {
        std::cout << "Friend status changed" << std::endl;
    }
};

void autoBroadcast() {
    std::cout << "Auto broadcasting" << std::endl;
}

int main() {
    Signal friendStatusChangedSignal;
    friendStatusChangedSignal.connect(Core::getInstance(), &Core::onFriendStatusChanged, autoBroadcast);

    // Emit the signal
    friendStatusChangedSignal.emitSignal();

    return 0;
}
