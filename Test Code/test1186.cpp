#include <iostream>
#include <GL/glew.h>

class Game {
private:
    int score;
    int health;
    static GLfloat g_vertex_buffer_data[100000];

public:
    Game() : score(0), health(100) {}

    void updateScore(int points) {
        score += points;
        if (score < 0) {
            score = 0;  // Ensure score doesn't go below 0
        }
    }

    void updateHealth(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;  // Ensure health doesn't go below 0
        }
    }

    int getScore() {
        return score;
    }

    int getHealth() {
        return health;
    }
};

// Define the static member array outside the class
GLfloat Game::g_vertex_buffer_data[100000];

int main() {
    Game game;
    game.updateScore(50);
    game.updateHealth(30);
    std::cout << "Score: " << game.getScore() << std::endl;  // Output: Score: 50
    std::cout << "Health: " << game.getHealth() << std::endl;  // Output: Health: 70
    return 0;
}
