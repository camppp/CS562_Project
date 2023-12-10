#include <iostream>
#include <utility>

class Window {
    // ... window implementation
};

class Application {
public:
    void run(Window&& window) {
        // ... start event loop with the given window
    }
};

int main() {
    Application app;
    Window window;

    // ... initialize window

    app.run(std::move(window));

    return 0;
}
