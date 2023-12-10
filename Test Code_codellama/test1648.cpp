#include <GLFW/glfw3.h>

class MouseProvider {
public:
    MouseProvider(GLFWwindow* window) {
        // Initialize GLFW
        glfwInit();

        // Set the GLFW window pointer
        this->window = window;

        // Set the GLFW mouse callback function
        glfwSetMouseButtonCallback(window, handleMouseButton);
        glfwSetCursorPosCallback(window, handleMouseMove);
        glfwSetScrollCallback(window, handleMouseScroll);
    }

    ~MouseProvider() {
        // Clean up GLFW
        glfwTerminate();
    }

    void handleMouseMove(double xPos, double yPos) {
        // Update the internal state of the MouseProvider class to reflect the new mouse position
        this->xPos = xPos;
        this->yPos = yPos;
    }

    void handleMouseButton(int button, int action, int mods) {
        // Update the internal state of the MouseProvider class based on the provided button, action, and modifier values
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            // Left mouse button pressed
            this->leftButtonPressed = true;
        } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
            // Left mouse button released
            this->leftButtonPressed = false;
        } else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
            // Right mouse button pressed
            this->rightButtonPressed = true;
        } else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
            // Right mouse button released
            this->rightButtonPressed = false;
        }
    }

    void handleMouseScroll(double xoffset, double yoffset) {
        // Update the internal state of the MouseProvider class based on the provided scroll offsets
        this->xScrollOffset = xoffset;
        this->yScrollOffset = yoffset;
    }

private:
    GLFWwindow* window;
    double xPos, yPos;
    bool leftButtonPressed, rightButtonPressed;
    double xScrollOffset, yScrollOffset;
};
