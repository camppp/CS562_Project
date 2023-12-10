#include <iostream>
#include <functional>

template <typename T>
class Event {
public:
    using EventHandler = std::function<void(T)>;

    void addHandler(const EventHandler& handler) {
        eventHandlers.push_back(handler);
    }

    void removeHandler(const EventHandler& handler) {
        eventHandlers.remove(handler);
    }

    void invoke(const T& arg) {
        for (const auto& handler : eventHandlers) {
            handler(arg);
        }
    }

private:
    std::list<EventHandler> eventHandlers;
};

class myObj {
public:
    void func(int arg) {
        std::cout << "Event invoked with argument: " << arg << std::endl;
    }
};

int main() {
    myObj mo;
    Event<int> so;

    if (so.myEvent != nullptr)
        so.myEvent(2); // will print once

    so.myEvent -= new method_delegate<myObj, int>(&mo, &myObj::func);

    if (so.myEvent != nullptr) // will fail as there are no more
        so.myEvent.invoke(3); // will not be printed

    return 0;
}
