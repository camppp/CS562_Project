#include <iostream>
#include <exception>
#include "SEngine.h"

using namespace std;

class MazeGame : public SEngine {
    vector<vector<char>> mazeGrid;  // 2D grid representing the maze
    int playerX, playerY;  // Player position

public:
    MazeGame() : mazeGrid(10, vector<char>(10, ' ')), playerX(1), playerY(1) {
        // Initialize the maze grid and player position
        // Populate the maze grid with obstacles and set the player's initial position
        mazeGrid[3][3] = 'X';  // Example obstacle
        mazeGrid[8][8] = 'G';  // Example goal
    }

    void OnUserCreate() override {
        // Draw the maze grid and player on the screen
        for (int y = 0; y < mazeGrid.size(); y++) {
            for (int x = 0; x < mazeGrid[y].size(); x++) {
                Draw(x, y, mazeGrid[y][x]);
            }
        }
        Draw(playerX, playerY, 'P');  // Draw the player
    }

    void OnUserUpdate(float fElapsedTime) override {
        // Handle player movement and collision logic
        if (GetKey(olc::Key::UP).bPressed && mazeGrid[playerY - 1][playerX] != 'X') {
            playerY--;
        }
        // Implement similar logic for down, left, and right movements

        // Check win condition
        if (mazeGrid[playerY][playerX] == 'G') {
            DrawString(20, 25, "You win!", olc::WHITE);
            return;
        }

        // Check lose condition
        if (mazeGrid[playerY][playerX] == 'X') {
            DrawString(20, 25, "Game over!", olc::WHITE);
            return;
        }

        // Redraw the maze grid and player
        for (int y = 0; y < mazeGrid.size(); y++) {
            for (int x = 0; x < mazeGrid[y].size(); x++) {
                Draw(x, y, mazeGrid[y][x]);
            }
        }
        Draw(playerX, playerY, 'P');
    }
};

int main() {
    MazeGame game;
    if (game.Construct(80, 50, 8, 8)) {
        game.Start();
    }
    return 0;
}
