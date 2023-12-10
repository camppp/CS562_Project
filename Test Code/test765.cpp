bool checkWin(char board[8][8], char playerPiece, int x, int y) {
  // Check horizontal direction
  for (int i = 0; i < 8; i++) {
    if (board[y][i] == playerPiece && board[y][i + 1] == playerPiece && board[y][i + 2] == playerPiece && board[y][i + 3] == playerPiece && board[y][i + 4] == playerPiece) {
      return true;
    }
  }

  // Check vertical direction
  for (int i = 0; i < 8; i++) {
    if (board[i][x] == playerPiece && board[i + 1][x] == playerPiece && board[i + 2][x] == playerPiece && board[i + 3][x] == playerPiece && board[i + 4][x] == playerPiece) {
      return true;
    }
  }

  // Check diagonal direction
  for (int i = 0; i < 8; i++) {
    if (board[i][i] == playerPiece && board[i + 1][i + 1] == playerPiece && board[i + 2][i + 2] == playerPiece && board[i + 3][i + 3] == playerPiece && board[i + 4][i + 4] == playerPiece) {
      return true;
    }
  }

  // Check anti-diagonal direction
  for (int i = 0; i < 8; i++) {
    if (board[i][7 - i] == playerPiece && board[i + 1][7 - i + 1] == playerPiece && board[i + 2][7 - i + 2] == playerPiece && board[i + 3][7 - i + 3] == playerPiece && board[i + 4][7 - i + 4] == playerPiece) {
      return true;
    }
  }

  return false;
}
