#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void mark_board(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    bool is_game_over() {
        return get_winner() != ' ' || is_board_full();
    }

    char get_winner() {
        // Check rows, columns, and diagonals for a winner
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return board[i][0];  // Row winner
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return board[0][i];  // Column winner
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];  // Diagonal winner (top-left to bottom-right)
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];  // Diagonal winner (top-right to bottom-left)
        }
        return ' ';  // No winner
    }

    bool is_board_full() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;  // Board is not full
                }
            }
        }
        return true;  // Board is full
    }

    void print_board() {
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    TicTacToe game;
    game.mark_board(3);  // x
    game.mark_board(5);  // o
    game.mark_board(4);  // x
    game.mark_board(6);  // o
    game.mark_board(8);  // x
    game.print_board();
    if (game.is_game_over()) {
        char winner = game.get_winner();
        if (winner != ' ') {
            std::cout << "Player " << winner << " wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    } else {
        std::cout << "Game is not over yet." << std::endl;
    }
    return 0;
}
