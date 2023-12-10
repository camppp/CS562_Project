#include <stdio.h>

void board_print(char (*board)[8]) {
    printf("  a b c d e f g h\n");
    for (int rank = 7; rank >= 0; rank--) {
        printf("%d ", rank + 1);
        for (int file = 0; file < 8; file++) {
            printf("%c ", board[rank][file]);
        }
        printf("\n");
    }
}
