#include <iostream>
#include <vector>

class GridGame {
    private:
        std::vector<std::vector<bool>> box;
        std::vector<std::vector<bool>> goal;

    public:
        GridGame(int rows, int cols) {
            box.resize(rows, std::vector<bool>(cols, false));
            goal.resize(rows, std::vector<bool>(cols, false));
        }

        void setBoxCell(int row, int col, bool value) {
            box[row][col] = value;
        }

        bool checkBoxCell(int row, int col) {
            return box[row][col];
        }

        void setGoalCell(int row, int col, bool value) {
            goal[row][col] = value;
        }

        bool checkGoalCell(int row, int col) {
            return goal[row][col];
        }
};
