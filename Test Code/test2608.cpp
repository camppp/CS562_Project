#include <iostream>

struct Color {
    int r, g, b;
};

void processColors(Color* colors, int max_iter, int num_shades, const Color* mapping, int size) {
    for (int i = 0; i < size; i++) {
        if (colors[i].r == max_iter || colors[i].r == 0) {
            colors[i].r = 0;
            colors[i].g = 0;
            colors[i].b = 0;
        } else {
            const int uc = colors[i].r % num_shades;
            colors[i] = mapping[uc];
        }
    }
}

int main() {
    // Example usage
    const int numColors = 6;
    Color colors[] = { {241, 233, 191}, {248, 201, 95}, {255, 170, 0}, {204, 128, 0}, {153, 87, 0}, {106, 52, 3} };
    const int max_iter = 255;
    const int num_shades = 5;
    Color mapping[] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}, {0, 255, 255} };

    processColors(colors, max_iter, num_shades, mapping, numColors);

    std::cout << "Processed Colors:" << std::endl;
    for (int i = 0; i < numColors; i++) {
        std::cout << "R: " << colors[i].r << " G: " << colors[i].g << " B: " << colors[i].b << std::endl;
    }

    return 0;
}
