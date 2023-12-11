void Player::move() {
  switch (direction) {
    case 'u':
      if (y > 0) {
        y--;
      }
      break;
    case 'd':
      if (y < gridSize - 1) {
        y++;
      }
      break;
    case 'l':
      if (x > 0) {
        x--;
      }
      break;
    case 'r':
      if (x < gridSize - 1) {
        x++;
      }
      break;
  }
}
