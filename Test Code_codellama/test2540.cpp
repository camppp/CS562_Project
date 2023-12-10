#include <iostream>
#include <string>

class TicTacToe {
public:
    TicTacToe() : board_{}, current_player_{'X'} {}

    void mark_board(int position) {
        if (position < 1 || position > 9) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        board_[position - 1] = current_player_;
        current_player_ = current_player_ == 'X' ? 'O' : 'X';
    }

    bool is_game_over() {
        for (int i = 0; i < 3; i++) {
            if (board_[i] == board_[i + 3] && board_[i] == board_[i + 6]) {
                return true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (board_[i] == board_[i + 1] && board_[i] == board_[i + 2]) {
                return true;
            }
        }

        if (board_[0] == board_[4] && board_[0] == board_[8]) {
            return true;
        }

        if (board_[2] == board_[4] && board_[2] == board_[6]) {
            return true;
        }

        return false;
    }

    std::string get_winner() {
        if (is_game_over()) {
            return current_player_ == 'X' ? "X" : "O";
        }

        return "";
    }

    void print_board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board_[i * 3 + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    char board_[9];
    char current_player_;
};
