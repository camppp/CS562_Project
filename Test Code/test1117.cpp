#include <stdio.h>

#define GRID_SIZE 5

// Function to move the player within the grid
int movePlayer(char grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY, char direction) {
    int newX = *playerX;
    int newY = *playerY;

    // Update new position based on movement direction
    if (direction == 'U') {
        newX--;
    } else if (direction == 'D') {
        newX++;
    } else if (direction == 'L') {
        newY--;
    } else if (direction == 'R') {
        newY++;
    }

    // Check if new position is within grid boundaries
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        return 0; // Movement failed, outside grid boundaries
    }

    // Check the type of tile at the new position
    char tile = grid[newX][newY];
    if (tile == 'X') {
        return 0; // Movement failed, obstacle encountered
    } else if (tile == 'T') {
        // Collect treasure and update player position
        grid[newX][newY] = '.';
        *playerX = newX;
        *playerY = newY;
        return 1; // Movement successful, treasure collected
    } else {
        // Move to empty space
        *playerX = newX;
        *playerY = newY;
        return 1; // Movement successful
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        {'.', '.', '.', '.', '.'},
        {'.', 'X', '.', 'T', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.'}
    };

    int playerX = 2;
    int playerY = 2;

    // Example usage of movePlayer function
    if (movePlayer(grid, &playerX, &playerY, 'U')) {
        printf("Player moved successfully to (%d, %d)\n", playerX, playerY);
    } else {
        printf("Player movement failed\n");
    }

    return 0;
}
