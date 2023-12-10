#include <iostream>

void diagonalSwap(int matrix[][3], int n) {
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][i];  // store the element on the main diagonal
        matrix[i][i] = matrix[i][n - 1 - i];  // swap with the element on the secondary diagonal
        matrix[i][n - 1 - i] = temp;  // assign the stored element to the secondary diagonal
    }
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;

    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    diagonalSwap(matrix, n);

    std::cout << "Matrix after diagonal swap:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
