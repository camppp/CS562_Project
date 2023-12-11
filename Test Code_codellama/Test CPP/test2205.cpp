#include <string>

std::string convertLayoutToAbbreviation(const std::string& type) {
  if (type == "LayoutTOCI") {
    return "TOCI";
  } else if (type == "LayoutIndex") {
    return "Index";
  } else if (type == "LayoutNonStruct") {
    return "NonStruct";
  } else if (type == "LayoutPrivate") {
    return "Private";
  } else if (type == "LayoutParagraph") {
    return "P";
  } else if (type == "LayoutHeading") {
    return "H";
  } else {
    return "Unknown";
  }
}
