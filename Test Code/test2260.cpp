#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char current_player;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), current_player('X') {}

    void mark_board(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == ' ') {
            board[row][col] = current_player;
            current_player = (current_player == 'X') ? 'O' : 'X';
        }
    }

    bool check_winner(char player) {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;  // Row win
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;  // Column win
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;  // Diagonal win
        }
        return false;
    }

    bool game_over() {
        // Check for a win
        if (check_winner('X') || check_winner('O')) {
            return true;
        }

        // Check for a draw
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;  // Game is not over, there are empty spaces
                }
            }
        }
        return true;  // Game is a draw
    }
};

int main() {
    TicTacToe* game = new TicTacToe();
    game->mark_board(1);  // X move
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;
    game->mark_board(2);
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;
    game->mark_board(3);
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;
    game->mark_board(4);
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;
    game->mark_board(5);
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;
    game->mark_board(7);
    std::cout << "Game over? " << (game->game_over() ? "Yes" : "No") << std::endl;

    delete game;
    return 0;
}
