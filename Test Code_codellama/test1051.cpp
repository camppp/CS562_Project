#include <iostream>
#include <vector>
#include <functional>

// Signal class
class Signal {
public:
    Signal(std::function<void()> slot) {
        slots_.push_back(slot);
    }

    void connect(std::function<void()> slot) {
        slots_.push_back(slot);
    }

    void emit() {
        for (auto& slot : slots_) {
            slot();
        }
    }

private:
    std::vector<std::function<void()>> slots_;
};

// Slot class
class Slot {
public:
    Slot(std::function<void()> slot) {
        slot_ = slot;
    }

    void execute() {
        slot_();
    }

private:
    std::function<void()> slot_;
};

int main() {
    // Create a signal
    Signal signal;

    // Connect a slot to the signal
    Slot slot([&]() {
        std::cout << "Hello, world!" << std::endl;
    });
    signal.connect(slot);

    // Emit the signal
    signal.emit();

    return 0;
}
