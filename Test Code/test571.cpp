// Virtual matrix base class
class Matrix {
public:
    virtual ~Matrix() = default;

    // Addition operator
    virtual Matrix& operator+(const Matrix& other) = 0;

    // Multiplication operator
    virtual Matrix& operator*(const Matrix& other) = 0;

    // Access element at position (i, j)
    virtual double& operator()(int i, int j) = 0;

    // Get number of rows
    virtual int getNumRows() const = 0;

    // Get number of columns
    virtual int getNumColumns() const = 0;
};

// General matrix class
class GeneralMatrix : public Matrix {
public:
    GeneralMatrix(int numRows, int numColumns) : numRows_(numRows), numColumns_(numColumns) {}

    // Addition operator
    GeneralMatrix& operator+(const GeneralMatrix& other) {
        // Implement addition operation for general matrices
        return *this;
    }

    // Multiplication operator
    GeneralMatrix& operator*(const GeneralMatrix& other) {
        // Implement multiplication operation for general matrices
        return *this;
    }

    // Access element at position (i, j)
    double& operator()(int i, int j) {
        // Implement access to elements for general matrices
        return data_[i * numColumns_ + j];
    }

    // Get number of rows
    int getNumRows() const {
        return numRows_;
    }

    // Get number of columns
    int getNumColumns() const {
        return numColumns_;
    }

private:
    int numRows_;
    int numColumns_;
    std::vector<double> data_;
};

// Diagonal matrix class
class DiagonalMatrix : public Matrix {
public:
    DiagonalMatrix(int numRows, int numColumns) : numRows_(numRows), numColumns_(numColumns) {}

    // Addition operator
    DiagonalMatrix& operator+(const DiagonalMatrix& other) {
        // Implement addition operation for diagonal matrices
        return *this;
    }

    // Multiplication operator
    DiagonalMatrix& operator*(const DiagonalMatrix& other) {
        // Implement multiplication operation for diagonal matrices
        return *this;
    }

    // Access element at position (i, j)
    double& operator()(int i, int j) {
        // Implement access to elements for diagonal matrices
        return data_[i * numColumns_ + j];
    }

    // Get number of rows
    int getNumRows() const {
        return numRows_;
    }

    // Get number of columns
    int getNumColumns() const {
        return numColumns_;
    }

private:
    int numRows_;
    int numColumns_;
    std::vector<double> data_;
};
