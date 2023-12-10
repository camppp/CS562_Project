#include <unordered_map>
#include <functional>
#include <iostream>

class String {
public:
    String(const char* str) {
        // Implementation not relevant for this problem
    }
    // Other methods and members are not relevant for this problem
};

class CallbackManager {
private:
    std::unordered_map<String, std::function<void()>> callbacks;

public:
    void registerCallback(String name, std::function<void()> callback) {
        callbacks[name] = callback;
    }

    void unregisterCallback(String name) {
        callbacks.erase(name);
    }

    void invokeCallback(String name) {
        if (callbacks.find(name) != callbacks.end()) {
            callbacks[name]();
        }
    }
};

int main() {
    CallbackManager manager;
    manager.registerCallback(String("onStart"), []() {
        std::cout << "Game started!" << std::endl;
    });

    manager.invokeCallback(String("onStart"));  // Output: Game started!

    manager.unregisterCallback(String("onStart"));
    manager.invokeCallback(String("onStart"));  // No output

    return 0;
}
