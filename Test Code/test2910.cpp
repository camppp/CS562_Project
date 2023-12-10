#include <string>

class Board {
public:
    Board(const std::string& grid) : grid_(grid) {}

    std::string read(int row, int col, Direction direction, int length) {
        std::string word;

        if (direction == Direction::Horizontal) {
            for (int i = 0; i < length; i++) {
                word += grid_[row][col + i];
            }
        } else if (direction == Direction::Vertical) {
            for (int i = 0; i < length; i++) {
                word += grid_[row + i][col];
            }
        }

        return word;
    }

private:
    std::string grid_;
};
