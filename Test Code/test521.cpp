#include <iostream>
#include <list>
#include <cstdlib>

void tokenizer(const std::string& line, char delimiter, std::list<const char*>& tokens) {
    // Split the line into tokens using the specified delimiter
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token.c_str());
    }

    // Extract the first token as the hostid
    int hostid = atoi(tokens.front());
    tokens.pop_front();

    // Print the hostid
    std::cout << "Host ID: " << hostid << std::endl;
}
