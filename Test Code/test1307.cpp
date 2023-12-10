#include <fmt/format.h>

namespace ae {
namespace virus {

struct Name {
  std::string name;

  friend std::ostream& operator<<(std::ostream& os, const Name& name) {
    return os << name.name;
  }
};

template <>
struct fmt::formatter<Name> {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const Name& name, FormatContext& ctx) {
    return format_to(ctx.begin(), "{}", name.name);
  }
};

} // namespace virus
} // namespace ae
