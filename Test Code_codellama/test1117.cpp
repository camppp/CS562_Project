int movePlayer(char grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY, char direction) {
    // Check if the movement is valid
    if (direction == 'U' && playerY > 0) {
        playerY--;
    } else if (direction == 'D' && playerY < GRID_SIZE - 1) {
        playerY++;
    } else if (direction == 'L' && playerX > 0) {
        playerX--;
    } else if (direction == 'R' && playerX < GRID_SIZE - 1) {
        playerX++;
    } else {
        return 0;
    }

    // Check if the player is on a treasure tile
    if (grid[playerY][playerX] == 'T') {
        grid[playerY][playerX] = '.';
        return 1;
    }

    // Check if the player is on an obstacle tile
    if (grid[playerY][playerX] == 'X') {
        return 0;
    }

    // Update the player's position
    return 1;
}
