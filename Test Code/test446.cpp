#include <iostream>
#include <vector>
#include <string>

enum Direction {
    Horizontal,
    Vertical
};

namespace ariel {
    class Board {
    private:
        std::vector<std::vector<char>> board;

    public:
        Board() {
            // Initialize the board with empty cells
            board = std::vector<std::vector<char>>(10, std::vector<char>(10, '_'));
        }

        ~Board() {
            // Destructor - no cleanup needed
        }

        void post(unsigned int row, unsigned int column, Direction d, std::string message) {
            if (d == Direction::Horizontal) {
                for (size_t i = 0; i < message.length(); i++) {
                    if (column + i < board[row].size()) {
                        board[row][column + i] = message[i];
                    }
                }
            } else if (d == Direction::Vertical) {
                for (size_t i = 0; i < message.length(); i++) {
                    if (row + i < board.size()) {
                        board[row + i][column] = message[i];
                    }
                }
            }
        }

        void show() {
            for (size_t i = 0; i < board.size(); i++) {
                for (size_t j = 0; j < board[i].size(); j++) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    };
}

int main() {
    ariel::Board board;
    board.post(2, 3, Direction::Horizontal, "hello");
    board.post(4, 5, Direction::Vertical, "world");
    board.show();
    return 0;
}
