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
