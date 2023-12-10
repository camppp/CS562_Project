class CallbackManager {
public:
    void registerCallback(String name, Function callback) {
        // Check if the callback function already exists
        if (callbacks.find(name) != callbacks.end()) {
            // Replace the existing callback function with the new one
            callbacks[name] = callback;
        } else {
            // Add the new callback function to the map
            callbacks[name] = callback;
        }
    }

    void unregisterCallback(String name) {
        // Check if the callback function exists
        if (callbacks.find(name) != callbacks.end()) {
            // Remove the callback function from the map
            callbacks.erase(name);
        }
    }

    void invokeCallback(String name) {
        // Check if the callback function exists
        if (callbacks.find(name) != callbacks.end()) {
            // Invoke the callback function
            callbacks[name]();
        }
    }

private:
    std::map<String, Function> callbacks;
};
