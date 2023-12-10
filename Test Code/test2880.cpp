#include <iostream>

enum class axis_t { X, Y, Z };

class AxisSystem {
private:
    axis_t majorAxis;
    axis_t minorAxis;
    double startAngle;
    double sweepAngle;

public:
    AxisSystem(axis_t major, axis_t minor, double start, double sweep)
        : majorAxis(major), minorAxis(minor), startAngle(start), sweepAngle(sweep) {}

    void setMajorAxis(axis_t axis) {
        majorAxis = axis;
    }

    void setMinorAxis(axis_t axis) {
        minorAxis = axis;
    }

    void setStartAngle(double angle) {
        startAngle = angle;
    }

    void setSweepAngle(double angle) {
        sweepAngle = angle;
    }

    axis_t getMajorAxis() const {
        return majorAxis;
    }

    axis_t getMinorAxis() const {
        return minorAxis;
    }

    double getStartAngle() const {
        return startAngle;
    }

    double getSweepAngle() const {
        return sweepAngle;
    }
};

int main() {
    AxisSystem axisSystem(axis_t::X, axis_t::Y, 0.0, 90.0);
    std::cout << "Major Axis: " << static_cast<int>(axisSystem.getMajorAxis()) << std::endl;
    std::cout << "Minor Axis: " << static_cast<int>(axisSystem.getMinorAxis()) << std::endl;
    std::cout << "Start Angle: " << axisSystem.getStartAngle() << std::endl;
    std::cout << "Sweep Angle: " << axisSystem.getSweepAngle() << std::endl;

    axisSystem.setMajorAxis(axis_t::Z);
    axisSystem.setStartAngle(45.0);

    std::cout << "Updated Major Axis: " << static_cast<int>(axisSystem.getMajorAxis()) << std::endl;
    std::cout << "Updated Start Angle: " << axisSystem.getStartAngle() << std::endl;

    return 0;
}
