#include <iostream>
#include <vector>

class Signal {
public:
    void connect(void* object, void (*slot)(), bool autoBroadcast = false) {
        // Add the slot to the list of connected slots
        connectedSlots.push_back(std::make_pair(object, slot));

        // If autoBroadcast is true, emit the signal immediately
        if (autoBroadcast) {
            emit();
        }
    }

    void emit() {
        // Iterate over the connected slots and call each one
        for (auto& slot : connectedSlots) {
            (*slot.second)();
        }
    }

private:
    std::vector<std::pair<void*, void (*)()>> connectedSlots;
};
