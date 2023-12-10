#include <iostream>
#include <vector>

template<typename T>
size_t coordinate_index(T c) {
    return static_cast<size_t>(c);
}

class GridSystem {
public:
    GridSystem(size_t dim_y, size_t dim_x) : dim_y_(dim_y), dim_x_(dim_x), grid_(dim_y * dim_x, 0) {}

    size_t cell_index(size_t y, size_t x, size_t u) {
        return cell_index_impl(y, x, u, dim_y_, dim_x_);
    }

    void set_cell_value(size_t y, size_t x, int value) {
        size_t index = cell_index(y, x, 0);
        if (index < grid_.size()) {
            grid_[index] = value;
        }
    }

    int get_cell_value(size_t y, size_t x) {
        size_t index = cell_index(y, x, 0);
        if (index < grid_.size()) {
            return grid_[index];
        }
        return -1; // Invalid cell
    }

private:
    size_t dim_y_;
    size_t dim_x_;
    std::vector<int> grid_;

    template<typename T>
    static size_t coord(T c) { return coordinate_index(c); }

    static size_t cell_index_impl(size_t y, size_t x, size_t u, size_t dim_y, size_t dim_x) {
        return u + 2 * (x + dim_x * y);
    }
};

int main() {
    GridSystem grid(3, 4);
    grid.set_cell_value(1, 2, 5);
    std::cout << grid.get_cell_value(1, 2) << std::endl; // Output: 5
    std::cout << grid.get_cell_value(0, 0) << std::endl; // Output: 0
    return 0;
}
