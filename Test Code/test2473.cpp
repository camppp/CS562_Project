#include <string>
#include <optional>

namespace metaf {

enum class ReportPart { RMK, ... };  // Other report parts omitted for brevity

enum class AppendResult { APPENDED, NOT_APPENDED };

class SecondaryLocationGroup {
public:
    static std::optional<SecondaryLocationGroup> parse(const std::string& group, ReportPart part) {
        // Implementation of parsing logic
        // Return an optional containing SecondaryLocationGroup on success, or an empty optional on failure
    }

    AppendResult append(const std::string& data, ReportPart part) {
        // Implementation of append logic
        // Return APPENDED if data is successfully appended, otherwise return NOT_APPENDED
    }

    // Other member functions and data members can be added as needed
};

}  // namespace metaf
