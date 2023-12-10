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
        // Add code to initialize the game window with width, height, and title
        std::cout << "Initializing game window with width: " << width << ", height: " << height << ", title: " << title << std::endl;
    }

    void run() {
        // Add game loop for updating and rendering the game
        std::cout << "Running game loop" << std::endl;
    }

    // Additional member functions for game development can be added here
    // For example:
    // void update() {}
    // void render() {}
};

int main() {
    Game game(800, 600, "hello");
    game.initialize();
    game.run();

    return 0;
}
