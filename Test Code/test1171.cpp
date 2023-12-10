#include <type_traits>
#include <sstream>

namespace rms {
  template <typename Stream, typename T, typename = void>
  struct is_streamable : std::false_type {};

  template <typename Stream, typename T>
  struct is_streamable<Stream, T, decltype(void(std::declval<Stream&>() << std::declval<T>()))> : std::true_type {};
}

// Test cases
TEST_CASE("Test streamable", "Type Traits") {
  bool test = rms::is_streamable<std::stringstream, std::string>::value;
  REQUIRE(test);
}

TEST_CASE("Serializable is streamable", "Type Traits") {
  std::stringstream ss;
  ss << Bar();
  REQUIRE(ss.str() == "this-is-bar");
  bool test = rms::is_streamable<std::stringstream, Bar>::value;
  REQUIRE(test);
}

TEST_CASE("Test not streamable", "Type Traits") {
  bool test = rms::is_streamable<std::stringstream, Foo>::value;
  REQUIRE_FALSE(test);
}
