#include <iostream>
#include <string>
#include <vector>

enum Direction {
    Horizontal,
    Vertical
};

class Board {
public:
    Board() {
        // Initialize the board with a 2D vector
        board = std::vector<std::vector<std::string>>(10, std::vector<std::string>(10, ""));
    }

    ~Board() {
        // Clean up the board
        board.clear();
    }

    void post(unsigned int row, unsigned int column, Direction d, std::string message) {
        // Check if the coordinates are valid
        if (row >= board.size() || column >= board[row].size()) {
            std::cout << "Invalid coordinates" << std::endl;
            return;
        }

        // Check if the direction is valid
        if (d == Horizontal) {
            // Post the message horizontally
            for (int i = 0; i < message.length(); i++) {
                board[row][column + i] = message[i];
            }
        } else if (d == Vertical) {
            // Post the message vertically
            for (int i = 0; i < message.length(); i++) {
                board[row + i][column] = message[i];
            }
        } else {
            std::cout << "Invalid direction" << std::endl;
            return;
        }
    }

private:
    std::vector<std::vector<std::string>> board;
};
