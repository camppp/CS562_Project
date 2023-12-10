class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows * cols) {}

    void FillWithValues(MWC& mwc, Matrix& B) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i * cols + j] = mwc.next();
            }
        }
    }

    void Release(int n = 1) {
        if (n == 1) {
            data.clear();
        } else {
            data.erase(data.begin(), data.begin() + n);
        }
    }

    int size() {
        return rows * cols;
    }

    void swap(Matrix& other) {
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
        std::swap(data, other.data);
    }

    Matrix operator-(Matrix& B) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i * cols + j] = data[i * cols + j] - B.data[i * cols + j];
            }
        }
        return result;
    }

    void Print(Matrix& M) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << M.data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows;
    int cols;
    std::vector<double> data;
};
