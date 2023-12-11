class Rectangle {
public:
    // Constructor
    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
    }

    // Methods
    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    bool isSquare() {
        return length == width;
    }

private:
    double length;
    double width;
};
