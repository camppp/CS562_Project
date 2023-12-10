#include <cmath>

template<class T>
class Point {
private:
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) {}

    void setCoordinates(T x, T y) {
        this->x = x;
        this->y = y;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    double distanceTo(const Point<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    Point<T> operator+(const Point<T>& other) const {
        return Point<T>(x + other.x, y + other.y);
    }
};
