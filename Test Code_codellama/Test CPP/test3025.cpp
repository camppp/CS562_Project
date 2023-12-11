class Child {
public:
    void addOnDrainCloseCb(std::function<void()> callback) {
        // Add the callback to the child's list of callbacks
        m_onDrainCloseCallbacks.push_back(callback);
    }

    void startDrainSequence() {
        // Initiate the drain sequence for the child
        // ...

        // Execute the registered callbacks in the correct order
        for (auto& callback : m_onDrainCloseCallbacks) {
            callback();
        }
    }

private:
    std::vector<std::function<void()>> m_onDrainCloseCallbacks;
};

class Parent {
public:
    void startDrainSequence(std::function<void()> callback) {
        // Initiate the drain sequence for the parent
        // ...

        // Execute the registered callbacks in the correct order
        for (auto& callback : m_onDrainCloseCallbacks) {
            callback();
        }
    }

private:
    std::vector<std::function<void()>> m_onDrainCloseCallbacks;
};
