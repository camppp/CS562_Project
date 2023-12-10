class Point {
public:
    // Constructors
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point(double radius, double angle) : radius(radius), angle(angle) {}

    // Methods to convert between Cartesian and polar coordinates
    void toPolar() {
        radius = sqrt(x*x + y*y);
        angle = atan2(y, x);
    }
    void toCartesian() {
        x = radius * cos(angle);
        y = radius * sin(angle);
    }

    // Methods to retrieve coordinates
    int getX() { return x; }
    int getY() { return y; }
    double getRadius() { return radius; }
    double getAngle() { return angle; }

private:
    int x, y;
    double radius, angle;
};
