#include <variant>
#include <string>

class Matrix {
public:
    virtual paddle::real* getRowBuf(int row) = 0;
    virtual size_t getWidth() = 0;
    virtual size_t getHeight() = 0;
};

struct Ptr {
    Matrix* mat;
};

std::variant<std::string, int> processMatrix(const Matrix& mat) {
    auto ptr = cast(mat);
    if (ptr->mat == nullptr) return "kPD_NULLPTR";
    size_t width = ptr->mat->getWidth();
    size_t height = ptr->mat->getHeight();
    return width * height;
}
