void OnUserCreate() override {
    // Initialize the maze grid
    maze = new int[mazeSize][mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        for (int j = 0; j < mazeSize; j++) {
            maze[i][j] = 0; // Initialize all cells to empty
        }
    }

    // Initialize the player position
    playerPosition = new int[2];
    playerPosition[0] = 0; // Initialize x position to 0
    playerPosition[1] = 0; // Initialize y position to 0
}
