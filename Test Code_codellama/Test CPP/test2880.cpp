class AxisSystem {
private:
    // Major axis
    Vector3 majorAxis;

    // Minor axis
    Vector3 minorAxis;

    // Start angle
    double startAngle;

    // Sweep angle
    double sweepAngle;

public:
    // Constructor
    AxisSystem(const Vector3& majorAxis, const Vector3& minorAxis, double startAngle, double sweepAngle)
        : majorAxis(majorAxis), minorAxis(minorAxis), startAngle(startAngle), sweepAngle(sweepAngle) {}

    // Set major axis
    void setMajorAxis(const Vector3& majorAxis) {
        this->majorAxis = majorAxis;
    }

    // Set minor axis
    void setMinorAxis(const Vector3& minorAxis) {
        this->minorAxis = minorAxis;
    }

    // Set start angle
    void setStartAngle(double startAngle) {
        this->startAngle = startAngle;
    }

    // Set sweep angle
    void setSweepAngle(double sweepAngle) {
        this->sweepAngle = sweepAngle;
    }

    // Get major axis
    Vector3 getMajorAxis() const {
        return majorAxis;
    }

    // Get minor axis
    Vector3 getMinorAxis() const {
        return minorAxis;
    }

    // Get start angle
    double getStartAngle() const {
        return startAngle;
    }

    // Get sweep angle
    double getSweepAngle() const {
        return sweepAngle;
    }
};
