#include <fmt/format.h>

namespace ae {
    namespace virus {
        struct Name {
            std::string name;

            // Define any necessary member functions and constructors for the ae::virus::Name type
            // ...

            // Define the custom formatter for ae::virus::Name
            template <typename FormatContext>
            auto format(const ae::virus::Name& ts, FormatContext& ctx) {
                return fmt::formatter<std::string_view>::format(static_cast<std::string_view>(ts.name), ctx);
            }
        };
    }
}

// Example usage:
int main() {
    ae::virus::Name virusName{"COVID-19"};
    std::string formatted = fmt::format("The virus name is: {}", virusName);
    // The formatted string will be "The virus name is: COVID-19"
    return 0;
}
