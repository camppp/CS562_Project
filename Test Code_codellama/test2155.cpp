#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> phone_filter(const std::vector<std::string>& numbers, int country_code) {
    std::vector<std::string> filtered_numbers;
    std::string country_code_str = "+" + std::to_string(country_code);

    for (const auto& number : numbers) {
        std::regex pattern("^(" + country_code_str + "|0)" + "-[0-9]{2,4}-[0-9]{4}$");
        if (std::regex_match(number, pattern)) {
            filtered_numbers.push_back(number);
        }
    }

    return filtered_numbers;
}
