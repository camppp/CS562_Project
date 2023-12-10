#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& input) : data(input) {}

    Matrix operator+(const Matrix& other) const {
        Matrix result(data.size(), std::vector<int>(data[0].size()));
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(data.size(), std::vector<int>(data[0].size()));
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(data.size(), std::vector<int>(data[0].size()));
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(data[0].size(), std::vector<int>(data.size()));
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[0].size(); j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
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
