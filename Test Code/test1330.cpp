#include <iostream>
#include <boost/spirit/include/karma.hpp>

namespace karma = boost::spirit::karma;

class generators {
public:
    static bool float_to_string(std::string &str, float number) {
        // Use boost::spirit::karma to convert float to string
        std::back_insert_iterator<std::string> outit(str);
        bool result = karma::generate(outit, karma::float_, number);
        return result;
    }
};

int main() {
    float inputNumber = 3.14159f;
    std::string outputString;
    if (generators::float_to_string(outputString, inputNumber)) {
        std::cout << "String representation of " << inputNumber << " is: " << outputString << std::endl;
    } else {
        std::cout << "Conversion failed" << std::endl;
    }
    return 0;
}
