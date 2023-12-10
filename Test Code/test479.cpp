class GeometricShape {
protected:
    double area;

public:
    GeometricShape() {}
    virtual ~GeometricShape() {}

    virtual void calculateArea() = 0;

    double getArea() {
        return area;
    }
};
