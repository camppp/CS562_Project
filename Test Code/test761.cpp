#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;

public:
    Matrix(const std::vector<std::vector<double>>& input) : data(input) {}

    double get_val(int row, int col) {
        return data[row][col];
    }

    void set_val(int row, int col, double value) {
        data[row][col] = value;
    }

    void add_value(int rows, int cols, double p) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                double new_val = get_val(i, j) + p;
                set_val(i, j, new_val);
            }
        }
    }
};

int main() {
    std::vector<std::vector<double>> initial_data = {{1.0, 2.0, 3.0},
                                                     {4.0, 5.0, 6.0},
                                                     {7.0, 8.0, 9.0}};
    Matrix mat(initial_data);
    mat.add_value(2, 2, 10.0);

    for (int i = 0; i < initial_data.size(); i++) {
        for (int j = 0; j < initial_data[i].size(); j++) {
            std::cout << mat.get_val(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
