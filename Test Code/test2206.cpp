#include <iostream>
#include <vector>

class Matrix {
private:
    bool useBias;
    std::vector<std::vector<int>> data;

public:
    Matrix() : useBias(false) {}

    void setUseBias(bool useBias) {
        this->useBias = useBias;
    }

    void resize(int rows, int cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Additional methods for matrix operations can be added here

    // Method to display the matrix for testing
    void displayMatrix() {
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix m;
    m.setUseBias(true);
    int N = 3, M = 4;
    m.resize(N, M);
    m.displayMatrix(); // Output: 0 0 0 0
                       //         0 0 0 0
                       //         0 0 0 0
    return 0;
}
