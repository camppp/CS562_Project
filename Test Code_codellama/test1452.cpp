#include <iostream>
#include <string>

namespace abel::gui {
    class Window {
    public:
        Window(const std::string& title) {
            // Initialize the window with the given title
            std::cout << "Initializing window with title: " << title << std::endl;
        }

        void show() {
            // Display the window
            std::cout << "Showing window" << std::endl;
        }

        void close() {
            // Close the window
            std::cout << "Closing window" << std::endl;
        }
    };
}
