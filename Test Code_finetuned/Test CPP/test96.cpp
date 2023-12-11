#include <deque>
#include <memory>

class ConnectionEvent {
    // Define connection event properties and methods
};

class SmartPtrConnectionListener {
public:
    virtual void onConnectionEvent(const ConnectionEvent& event) = 0;
};

class CompositeConnectionListener {
public:
    using ListenerDeque = std::deque<std::shared_ptr<SmartPtrConnectionListener>>;

    CompositeConnectionListener() {
        // Initialize the composite connection listener
    }

    ~CompositeConnectionListener() {
        // Destructor
    }

    void setDelegates(const ListenerDeque& delegates) {
        _delegates = delegates;
    }

    void addDelegate(const std::shared_ptr<SmartPtrConnectionListener>& delegate) {
        // Add a delegate to the list
        _delegates.push_back(delegate);
    }

    void removeDelegate(const std::shared_ptr<SmartPtrConnectionListener>& delegate) {
        // Remove a delegate from the list
        _delegates.erase(std::remove(_delegates.begin(), _delegates.end(), delegate), _delegates.end());
    }

    void notifyConnectionEvent(const ConnectionEvent& event) {
        // Notify all delegates of the connection event
        for (const auto& delegate : _delegates) {
            delegate->onConnectionEvent(event);
        }
    }

private:
    ListenerDeque _delegates;
};