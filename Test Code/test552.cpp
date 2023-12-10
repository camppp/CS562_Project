class Vector3D {
private:
    double x, y, z;

public:
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Add member functions to get the delta in Y and Z
    double getDeltaY() const { return y - getY(); }
    double getDeltaZ() const { return z - getZ(); }
};
