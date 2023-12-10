#include <iostream>
#include <sstream>
#include <string>
#include <regex>

// Define the color formatting function
template <int... colors>
std::string color(const std::string& text) {
    std::stringstream ss;
    ss << "\033[38;2;" << colors... << "m" << text << "\033[0m";
    return ss.str();
}

// Define the LEEStructLang parsing function
void parseLEEStructLangCode(const std::string& codeSnippet) {
    std::regex colorRegex(R"(\bcolor<(\d+)(?:,\s*(\d+)(?:,\s*(\d+))?)?>\b)");
    std::regex methodCallRegex(R"(\b([a-zA-Z_]\w*)\.(get\w+)\(\)\.(get\w+)\(\)\.(get\w+)\(\)\b)");

    std::smatch match;
    std::string::const_iterator searchStart(codeSnippet.cbegin());

    while (std::regex_search(searchStart, codeSnippet.cend(), match, colorRegex)) {
        std::cout << "Color: " << match.str(1);
        if (match.size() > 2) {
            std::cout << ", " << match.str(2);
            if (match.size() > 3) {
                std::cout << ", " << match.str(3);
            }
        }
        std::cout << std::endl;

        std::cout << "Text: " << match.suffix().str().substr(1, match.suffix().str().find('<') - 1) << std::endl;

        if (std::regex_search(match.suffix().str(), match, methodCallRegex)) {
            std::cout << "Method Call: " << match.str(1) << "." << match.str(2) << "()." << match.str(3) << "()." << match.str(4) << "()" << std::endl;
            // Call the method and print the return value
            // Replace the following line with actual method calls and their return values
            std::cout << "Method Return Value: <value returned by the method call>" << std::endl;
        }

        searchStart = match.suffix().first;
    }
}
