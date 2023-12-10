#include <iostream>

namespace rt {

std::ostream &operator<<(std::ostream &os, const color &color) {
  os << "Color r: " << color.m_x << " g: " << color.m_y << " b: " << color.m_z << " a: " << color.m_w << std::endl;
  return os;
}

} // namespace rt
