#include <iostream>

class Color {
private:
    int red;
    int green;
    int blue;

public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    // Add a method to calculate the grayscale value
    double calculateGrayscale() {
        return 0.2126 * red + 0.7152 * green + 0.0722 * blue;
    }
};

int main() {
    Color color(100, 150, 200);
    std::cout << "Grayscale value: " << color.calculateGrayscale() << std::endl;
    return 0;
}
