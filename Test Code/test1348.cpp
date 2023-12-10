#include <iostream>

// Define the CTabPtr data structure
class CTabPtr {
private:
    int colorTable[5]; // Assuming a color table of size 5
public:
    void setColor(int index, int color) {
        if (index >= 0 && index < 5) {
            colorTable[index] = color;
        } else {
            std::cout << "Index out of range" << std::endl;
        }
    }

    int getColor(int index) {
        if (index >= 0 && index < 5) {
            return colorTable[index];
        } else {
            std::cout << "Index out of range" << std::endl;
            return -1; // Return an invalid color value
        }
    }
};

int main() {
    // Sample usage of the CTabPtr data structure
    CTabPtr conv_table;

    // Set color values at specific indices
    conv_table.setColor(0, 255);
    conv_table.setColor(1, 128);
    conv_table.setColor(2, 0);
    conv_table.setColor(3, 192);
    conv_table.setColor(4, 64);

    // Retrieve color values at specific indices
    std::cout << "Color at index 2: " << conv_table.getColor(2) << std::endl;
    std::cout << "Color at index 5: " << conv_table.getColor(5) << std::endl; // This should print "Index out of range"

    return 0;
}
