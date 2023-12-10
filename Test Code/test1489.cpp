#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& input) : data(input) {}

    Matrix operator+(const Matrix& other) const {
        std::vector<std::vector<int>> result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[i].size(); ++j) {
                row.push_back(data[i][j] + other.data[i][j]);
            }
            result.push_back(row);
        }
        return Matrix(result);
    }

    Matrix operator-(const Matrix& other) const {
        std::vector<std::vector<int>> result;
        for (size_t i = 0; i < data.size(); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < data[i].size(); ++j) {
                row.push_back(data[i][j] - other.data[i][j]);
            }
            result.push_back(row);
        }
        return Matrix(result);
    }

    Matrix operator*(const Matrix& other) const {
        std::vector<std::vector<int>> result(data.size(), std::vector<int>(other.data[0].size(), 0));
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix(result);
    }

    Matrix transpose() const {
        std::vector<std::vector<int>> result(data[0].size(), std::vector<int>(data.size(), 0));
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result[j][i] = data[i][j];
            }
        }
        return Matrix(result);
    }

    void display() const {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> mat2 = {{7, 8, 9}, {10, 11, 12}};

    Matrix matrix1(mat1);
    Matrix matrix2(mat2);

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    (matrix1 + matrix2).display();

    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    (matrix1 - matrix2).display();

    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    (matrix1 * matrix2).display();

    std::cout << "Transpose of Matrix 1:" << std::endl;
    matrix1.transpose().display();

    return 0;
}
