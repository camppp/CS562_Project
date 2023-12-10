#include <iostream>
#include <vector>
#include <string>

enum class Direction { Horizontal, Vertical };

class Board {
private:
    std::vector<std::vector<char>> grid;

public:
    Board(const std::vector<std::vector<char>>& initialGrid) : grid(initialGrid) {}

    std::string read(int row, int col, Direction direction, int length) {
        std::string word;
        if (direction == Direction::Horizontal) {
            for (int i = col; i < col + length; ++i) {
                word += grid[row][i];
            }
        } else if (direction == Direction::Vertical) {
            for (int i = row; i < row + length; ++i) {
                word += grid[i][col];
            }
        }
        return word;
    }
};

int main() {
    std::vector<std::vector<char>> initialGrid = {
        {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'},
        {'V', 'e', 'r', 'y', ' ', 'N', 'i', 'c', 'e', ' ', 'T', 'o', ' ', 'M', 'e', 'e', 't', ' ', 'Y', 'o', 'u'},
        {'I', ' ', 'D', 'o', 'm', 'i', 'n', 'a', 't', 'e', ' ', 'T', 'h', 'i', 's', ' ', 'G', 'a', 'm', 'e'}
    };

    Board board(initialGrid);

    std::string word1 = board.read(1, 8, Direction::Horizontal, 4);  // Should return "Very"
    std::string word2 = board.read(2, 8, Direction::Horizontal, 4);  // Should return "Nice"
    std::string word3 = board.read(0, 6, Direction::Vertical, 6);    // Should return "World!"
    std::string word4 = board.read(0, 13, Direction::Vertical, 10);  // Should return "I Dominate"

    std::cout << "Word 1: " << word1 << std::endl;
    std::cout << "Word 2: " << word2 << std::endl;
    std::cout << "Word 3: " << word3 << std::endl;
    std::cout << "Word 4: " << word4 << std::endl;

    return 0;
}
