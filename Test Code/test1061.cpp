#include <iostream>
#include <unordered_map>
#include <tuple>

class ColorPalette {
private:
    std::unordered_map<std::string, std::tuple<int, int, int>> colors_;

public:
    void addColor(const std::string& colorName, int red, int green, int blue) {
        colors_[colorName] = std::make_tuple(red, green, blue);
    }

    std::tuple<int, int, int> getRGB(const std::string& colorName) {
        return colors_[colorName];
    }
};

int main() {
    ColorPalette palette;
    palette.addColor("yellowgreen", 154, 205, 50);
    auto rgb = palette.getRGB("yellowgreen");
    std::cout << "RGB values for yellowgreen: " << std::get<0>(rgb) << ", " << std::get<1>(rgb) << ", " << std::get<2>(rgb) << std::endl;
    return 0;
}
