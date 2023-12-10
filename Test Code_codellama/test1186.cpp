#include <iostream>

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
            score = 0;
        }
    }

    void updateHealth(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    int getScore() {
        return score;
    }

    int getHealth() {
        return health;
    }
};

GLfloat Game::g_vertex_buffer_data[100000];
