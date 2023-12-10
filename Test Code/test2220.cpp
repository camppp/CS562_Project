#include <string>
#include "Direction.hpp"
#include <map>
#define MAX_VALUE 4294967295

class Grid {
public:
    Grid(int rows, int cols) {
        // Initialize the grid with all cells having a value of 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = 0;
            }
        }
    }

    void updateCellValue(int row, int col, int value) {
        // Update the value of the cell at the specified row and column
        grid[row][col] = value;
    }

    int getCellValue(int row, int col) {
        // Return the value of the cell at the specified row and column
        return grid[row][col];
    }

    bool canMove(int row, int col, Direction direction) {
        // Check if it's possible to move from the cell at the specified row and column in the given direction
        switch (direction) {
            case Direction::UP:
                return row > 0;
            case Direction::DOWN:
                return row < grid.size() - 1;
            case Direction::LEFT:
                return col > 0;
            case Direction::RIGHT:
                return col < grid[0].size() - 1;
            default:
                return false;
        }
    }

    void move(int& row, int& col, Direction direction) {
        // Update the row and column coordinates based on the given direction
        switch (direction) {
            case Direction::UP:
                row--;
                break;
            case Direction::DOWN:
                row++;
                break;
            case Direction::LEFT:
                col--;
                break;
            case Direction::RIGHT:
                col++;
                break;
            default:
                break;
        }

        // Handle boundary checks for movements within the grid
        if (row < 0 || row >= grid.size()) {
            row = 0;
        }
        if (col < 0 || col >= grid[0].size()) {
            col = 0;
        }
    }

private:
    std::vector<std::vector<int>> grid;
};
