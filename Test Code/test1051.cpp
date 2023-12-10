#include <functional>
#include <vector>

template <typename... Args>
class Signal {
public:
    using SlotFunction = std::function<void(Args...)>;

    void connect(SlotFunction slot) {
        slots_.push_back(slot);
    }

    void emit(Args... args) {
        for (const auto& slot : slots_) {
            slot(args...);
        }
    }

private:
    std::vector<SlotFunction> slots_;
};

template <typename... Args>
class Slot {
public:
    using SlotFunction = std::function<void(Args...)>;

    Slot(SlotFunction function) : function_(function) {}

    void operator()(Args... args) {
        function_(args...);
    }

private:
    SlotFunction function_;
};
