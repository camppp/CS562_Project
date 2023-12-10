#include <iostream>
#include <cassert>

class size {
private:
    int width_;
    int height_;

public:
    size(int width, int height) : width_(width), height_(height) {}

    int width() const {
        return width_;
    }

    int height() const {
        return height_;
    }

    bool operator==(const size& other) const {
        return width_ == other.width_ && height_ == other.height_;
    }

    static const size empty;

    static void test_method_create_size_with_values() {
        size s(1, 2);
        assert(s == size(1, 2));
        assert(s != size::empty);
        assert(s.width() == 1);
        assert(s.height() == 2);
    }

    static void test_method_create_size_with_copy() {
        size s = {1, 2};
        assert(s == size(1, 2));
        assert(s != size::empty);
    }
};

const size size::empty = size(0, 0);

int main() {
    size::test_method_create_size_with_values();
    size::test_method_create_size_with_copy();
    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}
