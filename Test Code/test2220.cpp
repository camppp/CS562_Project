#include <string>
#include "Direction.hpp"
#include <map>
#define MAX_VALUE 4294967295

class Grid {
private:
    std::vector<std::vector<int>> grid;
    int rows, cols;

public:
    Grid(int numRows, int numCols) : rows(numRows), cols(numCols) {
        grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
    }

    void updateCellValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            grid[row][col] = value;
        }
    }

    int getCellValue(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return grid[row][col];
        }
        return -1; // Invalid cell
    }

    bool canMove(int row, int col, Direction direction) {
        if (direction == Direction::UP && row > 0) {
            return true;
        } else if (direction == Direction::DOWN && row < rows - 1) {
            return true;
        } else if (direction == Direction::LEFT && col > 0) {
            return true;
        } else if (direction == Direction::RIGHT && col < cols - 1) {
            return true;
        }
        return false;
    }

    void move(int& row, int& col, Direction direction) {
        if (canMove(row, col, direction)) {
            if (direction == Direction::UP) {
                row--;
            } else if (direction == Direction::DOWN) {
                row++;
            } else if (direction == Direction::LEFT) {
                col--;
            } else if (direction == Direction::RIGHT) {
                col++;
            }
        }
    }
};
