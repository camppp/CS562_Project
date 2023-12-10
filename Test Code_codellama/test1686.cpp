void updateCharacterMovementAndInteraction(const DIR_LEFT, const DIR_RIGHT, const l_location, const grid) {
    // Update the character's movement direction based on the user input
    if (DIR_LEFT) {
        l_location.x -= 1;
    } else if (DIR_RIGHT) {
        l_location.x += 1;
    }

    // Update the target location for the character's movement
    const targetLocation = l_location + DIR_LEFT;

    // Check if the target location is within the game boundaries
    if (targetLocation.x < 0 || targetLocation.x >= grid.width) {
        return;
    }

    // Update the character's movement direction based on the input
    if (DIR_LEFT) {
        l_location.x -= 1;
    } else if (DIR_RIGHT) {
        l_location.x += 1;
    }

    // Check if the character is moving into a cell containing a crate
    if (grid[targetLocation.x][targetLocation.y] == CRATE) {
        // Push the crate
        grid[targetLocation.x][targetLocation.y] = EMPTY;
    }
}
