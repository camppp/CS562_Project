void board_print(char board[8][8]) {
    // Print the ranks of the board
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Print the files of the board
    for (int i = 0; i < 8; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    // Print the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
