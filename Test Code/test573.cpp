#include <iostream>

class WindowSystem {
public:
    static bool windowStillExists(int handle) {
        // Implementation to check if the window with the given handle still exists
        return true;  // Placeholder return value
    }
};

class ContextHelper {
public:
    static bool makeContextCurrent(void* win) {
        // Implementation to set the rendering context to the provided window
        return true;  // Placeholder return value
    }
};

class log {
public:
    static void warn(const std::string& message) {
        // Implementation to log a warning message
        std::cout << "Warning: " << message << std::endl;
    }
};

class context_guard {
private:
    bool m_contextIsValid;

public:
    context_guard(bool contextIsValid) : m_contextIsValid(contextIsValid) {}

    ~context_guard() {
        if (!m_contextIsValid) {
            return;
        }

        ContextHelper::makeContextCurrent(nullptr);
    }
};

int main() {
    int windowHandle = 123;  // Replace with actual window handle
    if (!WindowSystem::windowStillExists(windowHandle)) {
        return 0;
    }

    bool contextIsValid = ContextHelper::makeContextCurrent(windowHandle);
    if (!contextIsValid) {
        log::warn("Context is no longer valid.");
    }

    // Example usage of context_guard
    context_guard guard(contextIsValid);

    // Perform rendering and other operations

    // context_guard will automatically clear the rendering context if it's still valid when it goes out of scope
    return 0;
}
