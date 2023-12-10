#include <iostream>
#include <string>

class TicTacToe {
public:
    TicTacToe() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 9; i++) {
            board[i] = ' ';
        }
    }

    void mark_board(int position) {
        // Check if the position is valid
        if (position < 1 || position > 9) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        // Mark the position with the current player's symbol
        board[position - 1] = current_player == 'X' ? 'O' : 'X';

        // Switch the current player
        current_player = current_player == 'X' ? 'O' : 'X';
    }

    bool game_over() {
        // Check if the game is over
        if (check_win() || check_draw()) {
            return true;
        }

        // If the game is not over, return false
        return false;
    }

private:
    char board[9];
    char current_player = 'X';

    bool check_win() {
        // Check if there is a row of three in a row
        for (int i = 0; i < 9; i += 3) {
            if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
                return true;
            }
        }

        // Check if there is a column of three in a column
        for (int i = 0; i < 3; i++) {
            if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2]) {
                return true;
            }
        }

        // Check if there is a diagonal of three in a diagonal
        if (board[0] == board[4] && board[4] == board[8]) {
            return true;
        }
        if (board[2] == board[4] && board[4] == board[6]) {
            return true;
        }

        // If there is no win, return false
        return false;
    }

    bool check_draw() {
        // Check if all the spaces on the board are filled
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                return false;
            }
        }

        // If all the spaces are filled, return true
        return true;
    }
};
