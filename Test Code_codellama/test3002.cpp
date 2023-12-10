#include <iostream>
#include <vector>
#include <string>
#include <wwiv/common.h>
#include <wwiv/sdk.h>
#include <wwiv/stl.h>
#include <wwiv/strings.h>

using namespace wwiv::common;
using namespace wwiv::sdk;
using namespace wwiv::stl;
using namespace wwiv::strings;

std::vector<std::string> removeDuplicates(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        if (std::find(result.begin(), result.end(), str) == result.end()) {
            result.push_back(str);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> input;
    std::cout << "Enter a list of strings, separated by spaces: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(input));
    std::vector<std::string> output = removeDuplicates(input);
    std::cout << "The unique strings are: ";
    for (const auto& str : output) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}
