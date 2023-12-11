#include <iostream>

// Define the data structure for the color conversion table
struct CTabPtr {
    int* colors;
    int size;

    // Constructor to initialize the color conversion table
    CTabPtr(int size) {
        this->size = size;
        this->colors = new int[size];
    }

    // Destructor to free the memory allocated for the color conversion table
    ~CTabPtr() {
        delete[] colors;
    }

    // Set the color value at the specified index in the color table
    void setColor(int index, int color) {
        if (index < size) {
            colors[index] = color;
        }
    }

    // Get the color value at the specified index from the color table
    int getColor(int index) {
        if (index < size) {
            return colors[index];
        }
        return 0;
    }
};

int main() {
    // Create a color conversion table with 10 entries
    CTabPtr conv_table(10);

    // Set the color value at index 0 to red
    conv_table.setColor(0, 0xFF0000);

    // Set the color value at index 1 to green
    conv_table.setColor(1, 0x00FF00);

    // Set the color value at index 2 to blue
    conv_table.setColor(2, 0x0000FF);

    // Get the color value at index 0 from the color table
    int color = conv_table.getColor(0);

    // Print the color value
    std::cout << "Color at index 0: " << std::hex << color << std::endl;

    // Get the color value at index 1 from the color table
    color = conv_table.getColor(1);

    // Print the color value
    std::cout << "Color at index 1: " << std::hex << color << std::endl;

    // Get the color value at index 2 from the color table
    color = conv_table.getColor(2);

    // Print the color value
    std::cout << "Color at index 2: " << std::hex << color << std::endl;

    return 0;
}
