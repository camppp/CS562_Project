namespace demofw
{
  namespace glfw
  {
    class MouseProvider
    {
    public:
      MouseProvider(GLFWwindow* window)
      : mWindow(window)
      {
        // Initialize mouse state and register GLFW callbacks
        glfwSetCursorPosCallback(window, handleMouseMoveCallback);
        glfwSetMouseButtonCallback(window, handleMouseButtonCallback);
        glfwSetScrollCallback(window, handleMouseScrollCallback);
      }

      void handleMouseMove(double xPos, double yPos)
      {
        // Update internal state with new mouse position
        // ...
      }

      void handleMouseButton(int button, int action, int mods)
      {
        // Update internal state based on button, action, and mods
        // ...
      }

      void handleMouseScroll(double xoffset, double yoffset)
      {
        // Update internal state based on scroll offsets
        // ...
      }

    private:
      GLFWwindow* mWindow;

      static void handleMouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
      {
        MouseProvider* mouseProvider = static_cast<MouseProvider*>(glfwGetWindowUserPointer(window));
        mouseProvider->handleMouseMove(xpos, ypos);
      }

      static void handleMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
      {
        MouseProvider* mouseProvider = static_cast<MouseProvider*>(glfwGetWindowUserPointer(window));
        mouseProvider->handleMouseButton(button, action, mods);
      }

      static void handleMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
      {
        MouseProvider* mouseProvider = static_cast<MouseProvider*>(glfwGetWindowUserPointer(window));
        mouseProvider->handleMouseScroll(xoffset, yoffset);
      }
    };
  }
}
