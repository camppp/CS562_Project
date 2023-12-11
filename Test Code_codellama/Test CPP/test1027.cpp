void legalMove(int legalMove[BOARD_SIZE * BOARD_SIZE], int qiAfterMove[BOARD_SIZE * BOARD_SIZE], size_t& len)
{
    // Initialize the arrays
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        legalMove[i] = -1;
        qiAfterMove[i] = -1;
    }

    // Iterate over all possible moves
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            // Check if the move is legal
            if (isLegalMove(x, y))
            {
                // Add the move to the list of legal moves
                legalMove[len] = x * BOARD_SIZE + y;
                qiAfterMove[len] = getLibertiesAfterMove(x, y);
                len++;
            }
        }
    }
}

bool isLegalMove(int x, int y)
{
    // Check if the move is not self-capture
    if (board[x][y] == 1)
        return false;

    // Check if the move is not suicide
    if (getLibertiesAfterMove(x, y) == 0)
        return false;

    // Check if the move is not illegal
    if (isIllegalMove(x, y))
        return false;

    // The move is legal
    return true;
}

int getLibertiesAfterMove(int x, int y)
{
    // Count the number of liberties after the move
    int liberties = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 1 && !isSameColor(x, y, i, j))
                liberties++;
        }
    }
    return liberties;
}

bool isSameColor(int x1, int y1, int x2, int y2)
{
    // Check if the two points have the same color
    return board[x1][y1] == board[x2][y2];
}

bool isIllegalMove(int x, int y)
{
    // Check if the move is illegal
    if (board[x][y] == 0)
        return true;

    // Check if the move is illegal due to filling own eyes
    if (getLibertiesAfterMove(x, y) == 0)
        return true;

    // The move is not illegal
    return false;
}
