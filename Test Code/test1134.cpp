#include <iostream>
#include <unordered_map>
#include <functional>

class Window {
public:
    void GetSize(int& width, int& height) {
        // Implementation to get window size
    }
    void SetKeyPressFunction(std::function<void(int, int, int, int)> keyPressFunction) {
        // Implementation to set key press function
    }
};

class App {
public:
    void Open() {
        // Implementation to open the application
    }
};

class Lab5 : public App {
private:
    Window* window;
    std::unordered_map<int, std::function<void()>> keyActions;

public:
    bool Open() {
        App::Open();
        this->window = new Window;
        int w, h;
        this->window->GetSize(w, h);
        window->SetKeyPressFunction([this](int key, int, int action, int)
        {
            this->keyEvent(key, action);
            std::cout << "Key: " << key << " action: " << action << std::endl;
        });
        return true;
    }

    void keyEvent(int key, int action) {
        if (action == 1) {
            if (keyActions.find(key) != keyActions.end()) {
                keyActions[key]();
            }
        }
    }

    void mapKeyToAction(int key, std::function<void()> action) {
        keyActions[key] = action;
    }
};

int main() {
    Lab5 app;
    app.Open();

    // Example of mapping key 'A' to a specific action
    app.mapKeyToAction('A', []() {
        std::cout << "Action for key 'A' is executed" << std::endl;
    });

    // Pressing key 'A' will trigger the associated action
    return 0;
}
