#include <iostream>
#include <sstream>

std::string float_to_string(float number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}
