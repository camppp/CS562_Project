#include <iostream>
#include <mizuiro/image/format/color_ns/types/value_type.hpp>

// Define a custom color type
struct MyColor {
    using value_type = int; // Define the value type of the color
};

int main() {
    // Extract the value type of the color using the Mizuiro library
    using color_value_type = mizuiro::image::format::color_ns::types::value_type<MyColor>;

    // Output the value type of the color
    std::cout << "Value type of the color: " << typeid(color_value_type).name() << std::endl;

    return 0;
}
