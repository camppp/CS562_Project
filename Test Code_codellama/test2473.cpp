#include <optional>
#include <string>
#include <utility>

namespace metaf {

class SecondaryLocationGroup {
 public:
  static std::optional<SecondaryLocationGroup> parse(const std::string& group,
                                                     ReportPart part) {
    // Implement parsing logic here
    // ...

    if (success) {
      return SecondaryLocationGroup(group, part);
    } else {
      return std::nullopt;
    }
  }

  AppendResult append(const std::string& data, ReportPart part) {
    // Implement appending logic here
    // ...

    if (success) {
      return AppendResult::APPENDED;
    } else {
      return AppendResult::NOT_APPENDED;
    }
  }

 private:
  SecondaryLocationGroup(const std::string& group, ReportPart part)
      : group_(group), part_(part) {}

  std::string group_;
  ReportPart part_;
};

}  // namespace metaf
