template<typename T, int N>
class rect_tt {
public:
    // Construct a rectangle with specified dimensions and data type
    rect_tt(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {}

    // Access and modify the rectangle's dimensions and data type
    T getX() const { return x; }
    T getY() const { return y; }
    T getWidth() const { return width; }
    T getHeight() const { return height; }
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }
    void setWidth(T width) { this->width = width; }
    void setHeight(T height) { this->height = height; }

    // Calculate the area of the rectangle
    T area() const { return width * height; }

    // Check if a point lies within the rectangle
    bool contains(T x, T y) const {
        return x >= this->x && x <= this->x + width &&
               y >= this->y && y <= this->y + height;
    }

private:
    T x;
    T y;
    T width;
    T height;
};
