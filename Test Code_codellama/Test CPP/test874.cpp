#include <mizuiro/image/format/color_ns/types/value_type.hpp>

int main() {
    // Define a color type using the Mizuiro library
    using color_type = mizuiro::image::format::color_ns::types::value_type<mizuiro::image::format::color_ns::types::rgba8>;

    // Extract the value type of the color
    using value_type = mizuiro::image::format::color_ns::types::value_type<color_type>;

    // Output the value type of the color
    std::cout << "Value type of the color: " << value_type::name() << std::endl;

    return 0;
}
