#include <iostream>
#include <map>

class Lab5 : public App {
public:
    Lab5() {
        // Create a new window
        window = new Window();

        // Set the key press function
        window->setKeyPressFunction([this](int key, int action) {
            keyEvent(key, action);
        });
    }

    void keyEvent(int key, int action) {
        // Look up the action associated with the pressed key
        auto it = keyActions.find(key);
        if (it != keyActions.end()) {
            // Execute the associated action
            it->second();
        }
    }

private:
    // Data structure to store key-action mappings
    std::map<int, std::function<void()>> keyActions;

    // Window object
    Window* window;
};
