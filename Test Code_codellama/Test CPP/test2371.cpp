template <typename T, int N>
class vector_ref {
public:
    vector_ref(const vector<T, N>& vec, int start_row, int start_col, int num_rows, int num_cols)
        : vec_(vec), start_row_(start_row), start_col_(start_col), num_rows_(num_rows), num_cols_(num_cols) {}

    vector_ref& operator=(const vector_ref& other) {
        for (int i = 0; i < num_rows_; i++) {
            for (int j = 0; j < num_cols_; j++) {
                vec_[start_row_ + i][start_col_ + j] = other.vec_[start_row_ + i][start_col_ + j];
            }
        }
        return *this;
    }

    vector_ref& operator+=(const vector_ref& other) {
        for (int i = 0; i < num_rows_; i++) {
            for (int j = 0; j < num_cols_; j++) {
                vec_[start_row_ + i][start_col_ + j] += other.vec_[start_row_ + i][start_col_ + j];
            }
        }
        return *this;
    }

    vector_ref& operator-=(const vector_ref& other) {
        for (int i = 0; i < num_rows_; i++) {
            for (int j = 0; j < num_cols_; j++) {
                vec_[start_row_ + i][start_col_ + j] -= other.vec_[start_row_ + i][start_col_ + j];
            }
        }
        return *this;
    }

    vector_ref& operator*=(const vector_ref& other) {
        for (int i = 0; i < num_rows_; i++) {
            for (int j = 0; j < num_cols_; j++) {
                vec_[start_row_ + i][start_col_ + j] *= other.vec_[start_row_ + i][start_col_ + j];
            }
        }
        return *this;
    }

    vector_ref& operator/=(const vector_ref& other) {
        for (int i = 0; i < num_rows_; i++) {
            for (int j = 0; j < num_cols_; j++) {
                vec_[start_row_ + i][start_col_ + j] /= other.vec_[start_row_ + i][start_col_ + j];
            }
        }
        return *this;
    }

private:
    const vector<T, N>& vec_;
    int start_row_;
    int start_col_;
    int num_rows_;
    int num_cols_;
};
