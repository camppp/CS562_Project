#include <iostream>

void process_rect(float x, float y, float z[5], float C) {
    float area = 2 * (z[0] * z[1] + z[1] * z[2] + z[2] * z[0]);
    float volume = z[0] * z[1] * z[2];

    std::cout << "Area of the rectangle: " << area << std::endl;
    std::cout << "Volume of the rectangular prism: " << volume << std::endl;
}
