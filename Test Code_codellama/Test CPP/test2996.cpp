class Grid {
public:
    // Constructor
    Grid(size_t rows, size_t cols) : rows_(rows), cols_(cols), missing_val_(0) {}

    // Destructor
    ~Grid() {}

    // Member functions
    bool EqualsMissingValue(int val) const {
        return val == missing_val_;
    }

    bool GetMissingAt(size_t i, size_t j) const {
        return (*this)(i, j) == missing_val_;
    }

    void SetMissingAt(size_t i, size_t j) {
        (*this)(i, j) = missing_val_;
    }

private:
    size_t rows_;
    size_t cols_;
    int missing_val_;
};
