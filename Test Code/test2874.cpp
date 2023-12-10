template<class T>
class Point {
private:
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) {}

    void setCoordinates(T newX, T newY) {
        x = newX;
        y = newY;
    }

    T getX() {
        return x;
    }

    T getY() {
        return y;
    }

    T distanceTo(const Point<T>& other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    Point<T> operator+(const Point<T>& other) {
        return Point<T>(x + other.x, y + other.y);
    }
};
