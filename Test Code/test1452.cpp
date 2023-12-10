#include <iostream>

namespace abel::gui {
    class Window {
    private:
        std::string title;

    public:
        Window(const std::string& windowTitle) : title(windowTitle) {
            // Initialize the window with the provided title
            std::cout << "Window '" << title << "' initialized." << std::endl;
        }

        void show() {
            // Display the window
            std::cout << "Window '" << title << "' displayed." << std::endl;
        }

        void close() {
            // Close the window
            std::cout << "Window '" << title << "' closed." << std::endl;
        }
    };
}

int main() {
    // Create a window and demonstrate its functionalities
    abel::gui::Window mainWindow("Main Window");
    mainWindow.show();
    mainWindow.close();

    return 0;
}
