#include <iostream>
#include <string>

int countEndifs(const std::string& code) {
    int count = 0;
    for (const auto& c : code) {
        if (c == '#' && code[i + 1] == 'e' && code[i + 2] == 'n' && code[i + 3] == 'd' && code[i + 4] == 'i' && code[i + 5] == 'f') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string code = "#endif\n#endif\n";
    std::cout << countEndifs(code) << std::endl;
    return 0;
}
