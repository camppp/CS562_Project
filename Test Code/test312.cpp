#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    void FillWithValues(const std::vector<std::vector<int>>& MWC, const Matrix& B) {
        // Fill the matrix with values from MWC and B
        // Implementation depends on the specific requirements
    }

    void Release(int n = 1) {
        // Release memory, freeing up n units of memory
        // Implementation depends on the specific requirements
    }

    int size() const {
        // Return the size of the matrix
        // Implementation depends on the specific requirements
    }

    void swap(Matrix& other) {
        // Swap the contents of the current matrix with another matrix
        // Implementation depends on the specific requirements
    }

    Matrix operator-(const Matrix& other) const {
        // Overload the - operator to perform matrix subtraction
        // Implementation depends on the specific requirements
        Matrix result;
        // Perform matrix subtraction and store the result in 'result'
        return result;
    }

    void Print(const Matrix& M) const {
        // Print the contents of the matrix M
        // Implementation depends on the specific requirements
    }
};

// Implement the member functions of the Matrix class as per the specific requirements
