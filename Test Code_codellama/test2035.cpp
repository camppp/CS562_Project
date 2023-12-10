#include <sge/x11input/xim/method.hpp>
#include <sge/x11input/xim/supported_styles_unique_ptr.hpp>

sge::x11input::xim::supported_styles_unique_ptr get_supported_styles(sge::x11input::xim::method const &method)
{
    // Create a new supported_styles_unique_ptr object
    auto supported_styles = std::make_unique<sge::x11input::xim::supported_styles_unique_ptr>();

    // Retrieve the supported input method styles for the given method
    auto supported_styles_list = method.get_supported_styles();

    // Iterate over the supported styles and add them to the supported_styles_unique_ptr object
    for (auto &style : supported_styles_list)
    {
        supported_styles->push_back(style);
    }

    return supported_styles;
}
