#include <unordered_map>
#include <string>
#include <memory>

class Window {
public:
    // ...
};

class WindowManager {
public:
    Window& createWindow(const std::string& identifier, std::unique_ptr<Window> window) {
        // Transfer ownership of the Window object to the window management system
        m_windows[identifier] = std::move(window);

        // Return a reference to the added window
        return *m_windows[identifier];
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Window>> m_windows;
};
