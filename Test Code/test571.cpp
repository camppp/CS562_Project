#include <iostream>
#include <vector>

// Virtual matrix class
class VirtualMatrix {
public:
    virtual void add(const VirtualMatrix& other) = 0;
    virtual void multiply(const VirtualMatrix& other) = 0;
    virtual int getElement(int row, int col) const = 0;
    virtual void setElement(int row, int col, int value) = 0;
    virtual void print() const = 0;
    virtual ~VirtualMatrix() {}
};

// General matrix class
class GeneralMatrix : public VirtualMatrix {
private:
    std::vector<std::vector<int>> matrix;

public:
    GeneralMatrix(int rows, int cols) : matrix(rows, std::vector<int>(cols, 0)) {}

    void add(const VirtualMatrix& other) override {
        // Implementation for matrix addition
    }

    void multiply(const VirtualMatrix& other) override {
        // Implementation for matrix multiplication
    }

    int getElement(int row, int col) const override {
        return matrix[row][col];
    }

    void setElement(int row, int col, int value) override {
        matrix[row][col] = value;
    }

    void print() const override {
        // Implementation for printing the matrix
    }
};

// Diagonal matrix class
class DiagonalMatrix : public VirtualMatrix {
private:
    std::vector<int> diagonal;

public:
    DiagonalMatrix(int size) : diagonal(size, 0) {}

    void add(const VirtualMatrix& other) override {
        // Implementation for matrix addition
    }

    void multiply(const VirtualMatrix& other) override {
        // Implementation for matrix multiplication
    }

    int getElement(int row, int col) const override {
        if (row == col) {
            return diagonal[row];
        } else {
            return 0; // Non-diagonal elements are always 0
        }
    }

    void setElement(int row, int col, int value) override {
        if (row == col) {
            diagonal[row] = value;
        }
    }

    void print() const override {
        // Implementation for printing the matrix
    }
};

int main() {
    // Example usage of the matrix abstraction package
    VirtualMatrix* matrix1 = new GeneralMatrix(3, 3);
    VirtualMatrix* matrix2 = new DiagonalMatrix(3);

    // Perform matrix operations using the common interface
    matrix1->add(*matrix2);
    matrix1->multiply(*matrix2);

    delete matrix1;
    delete matrix2;

    return 0;
}
