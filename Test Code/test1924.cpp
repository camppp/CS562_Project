#include <iostream>

void process_rect(float x, float y, float z[5], float C) {
    float area = 2 * (z[0] * z[1] + z[1] * z[2] + z[2] * z[0]);
    float volume = z[0] * z[1] * z[2];

    std::cout << "Area of the rectangle: " << area << std::endl;
    std::cout << "Volume of the rectangular prism: " << volume << std::endl;
}

int main() {
    float center_x = 1.0, center_y = 2.0, side_lengths[5] = {3.0, 4.0, 5.0};
    float constant_C = 10.0;

    process_rect(center_x, center_y, side_lengths, constant_C);

    return 0;
}
