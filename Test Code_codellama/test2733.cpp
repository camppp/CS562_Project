#include <iostream>
#include <string>

class Game {
private:
    int width;
    int height;
    std::string title;

public:
    Game(int w, int h, std::string t) : width(w), height(h), title(t) {}

    void initialize() {
        // Initialize the game window with the specified width, height, and title
        std::cout << "Initializing game window with width: " << width << ", height: " << height << ", title: " << title << std::endl;

        // Set up the game window
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create the game window
        GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (window == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);

        // Initialize GLEW
        glewExperimental = true;
        if (glewInit() != GLEW_OK) {
            std::cout << "Failed to initialize GLEW" << std::endl;
            glfwTerminate();
            return;
        }

        // Set up viewport
        glViewport(0, 0, width, height);
    }

    void run() {
        // Game loop
        while (!glfwWindowShouldClose(window)) {
            // Update game state
            update();

            // Render game state
            render();

            // Swap buffers
            glfwSwapBuffers(window);

            // Poll for events
            glfwPollEvents();
        }

        // Clean up
        glfwTerminate();
    }

    void update() {
        // Update game state
    }

    void render() {
        // Render game state
    }
};
