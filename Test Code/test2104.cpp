void Player::move() {
  int newX = x;
  int newY = y;

  // Update the position based on the current direction
  switch (direction) {
    case Direction::UP:
      newY = (y > 0) ? y - 1 : y;  // Move up if not at the top boundary
      break;
    case Direction::DOWN:
      newY = (y < GRID_HEIGHT - 1) ? y + 1 : y;  // Move down if not at the bottom boundary
      break;
    case Direction::LEFT:
      newX = (x > 0) ? x - 1 : x;  // Move left if not at the left boundary
      break;
    case Direction::RIGHT:
      newX = (x < GRID_WIDTH - 1) ? x + 1 : x;  // Move right if not at the right boundary
      break;
  }

  // Update the player's position if it's a valid move
  if (newX != x || newY != y) {
    x = newX;
    y = newY;
  }
}
