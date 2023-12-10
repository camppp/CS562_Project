#include <iostream>
#include <utility>

class Window {
public:
    Window() = default;
    ~Window() = default;

    // Move constructor
    Window(Window&& other) noexcept :
        width(other.width),
        height(other.height)
    {
        std::cout << "Moving window" << std::endl;
    }

    // Move assignment operator
    Window& operator=(Window&& other) noexcept {
        width = other.width;
        height = other.height;
        std::cout << "Moving window" << std::endl;
        return *this;
    }

    int width = 0;
    int height = 0;
};

class Application {
public:
    Application() = default;
    ~Application() = default;

    void run(Window&& window) {
        std::cout << "Running application" << std::endl;
        // ...
    }
};
