class Matrix {
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        data_ = new double[rows * cols];
    }

    ~Matrix() {
        delete[] data_;
    }

    void setUseBias(bool useBias) {
        useBias_ = useBias;
    }

    void resize(int rows, int cols) {
        if (rows != rows_ || cols != cols_) {
            delete[] data_;
            data_ = new double[rows * cols];
            rows_ = rows;
            cols_ = cols;
        }
    }

    double get(int row, int col) {
        return data_[row * cols_ + col];
    }

    void set(int row, int col, double value) {
        data_[row * cols_ + col] = value;
    }

private:
    int rows_;
    int cols_;
    double* data_;
    bool useBias_;
};
