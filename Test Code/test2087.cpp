#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>

// Custom deleter for GLFW window
struct DestroyglfwWin {
    void operator()(GLFWwindow* window) const {
        glfwDestroyWindow(window);
    }
};

// CustomUniquePtr class template
template <typename T, typename Deleter>
class CustomUniquePtr {
public:
    explicit CustomUniquePtr(T* ptr, Deleter deleter) : ptr_(ptr), deleter_(deleter) {}

    ~CustomUniquePtr() {
        if (ptr_) {
            deleter_(ptr_);
        }
    }

    CustomUniquePtr(const CustomUniquePtr&) = delete;
    CustomUniquePtr& operator=(const CustomUniquePtr&) = delete;

    T* operator->() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    CustomUniquePtr& operator=(T* ptr) {
        if (ptr_ != ptr) {
            if (ptr_) {
                deleter_(ptr_);
            }
            ptr_ = ptr;
        }
        return *this;
    }

private:
    T* ptr_;
    Deleter deleter_;
};

int main() {
    int width = 800;
    int height = 600;
    const char* title = "CustomUniquePtr Example";

    GLFWwindow* glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!glfwWindow) {
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    CustomUniquePtr<GLFWwindow, DestroyglfwWin> window(glfwWindow, DestroyglfwWin());

    // Usage example
    glfwMakeContextCurrent(window.get());
    while (!glfwWindowShouldClose(window.get())) {
        // Rendering loop
        glfwSwapBuffers(window.get());
        glfwPollEvents();
    }

    return 0;
}
