// Event.h
#include <functional>

template <typename T>
class Event {
public:
    using Handler = std::function<void(T)>;

    void addHandler(Handler handler) {
        handlers.push_back(handler);
    }

    void removeHandler(Handler handler) {
        handlers.erase(std::remove(handlers.begin(), handlers.end(), handler), handlers.end());
    }

    void invoke(T arg) {
        for (auto& handler : handlers) {
            handler(arg);
        }
    }

private:
    std::vector<Handler> handlers;
};

// EventHandler.h
#include "Event.h"

template <typename T>
class EventHandler {
public:
    EventHandler(Event<T>& event) : event(event) {}

    void addHandler(typename Event<T>::Handler handler) {
        event.addHandler(handler);
    }

    void removeHandler(typename Event<T>::Handler handler) {
        event.removeHandler(handler);
    }

    void invoke(T arg) {
        event.invoke(arg);
    }

private:
    Event<T>& event;
};

// Object.h
#include "Event.h"

template <typename T>
class Object {
public:
    Object() {}

    void addHandler(typename Event<T>::Handler handler) {
        event.addHandler(handler);
    }

    void removeHandler(typename Event<T>::Handler handler) {
        event.removeHandler(handler);
    }

    void invoke(T arg) {
        event.invoke(arg);
    }

private:
    Event<T> event;
};

// main.cpp
#include "Event.h"
#include "EventHandler.h"
#include "Object.h"

int main() {
    Event<int> event;
    EventHandler<int> handler(event);

    handler.addHandler([](int x) { std::cout << "Event handler called with argument: " << x << std::endl; });

    event.invoke(42);

    return 0;
}
