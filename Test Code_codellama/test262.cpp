class Point {
public:
    Point(int x, int y) : x(x), y(y) {}

    int distance(const Point& other) const {
        return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
    }

    int distanceFromOrigin() const {
        return sqrt(x * x + y * y);
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

private:
    int x;
    int y;
};
