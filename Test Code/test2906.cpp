#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string line;
    std::regex copyrightRegex(R"(// Copyright \(c\) (\d{4}) by (.+)\. All rights reserved\.)");
    std::smatch match;

    while (std::getline(std::cin, line))
    {
        if (std::regex_search(line, match, copyrightRegex))
        {
            std::cout << "Author: " << match[2] << ", Date: 12/26/" << match[1] << "-07:57:22" << std::endl;
        }
    }

    return 0;
}
