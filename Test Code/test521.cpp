#include <iostream>
#include <list>
#include <cstdlib>
#include <string>

void tokenizer(const std::string& line, char delimiter, std::list<const char*>& tokens) {
    std::string token;
    std::istringstream tokenStream(line);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token.c_str());
    }
}

int main() {
    std::string line = "123,example,data";
    std::list<const char*> tokens;

    tokenizer(line, ',', tokens);

    std::list<const char*>::iterator I = tokens.begin();

    int hostid = atoi(*I); ++I;

    std::cout << "Host ID: " << hostid << std::endl;

    return 0;
}
