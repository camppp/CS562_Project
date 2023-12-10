#include <iostream>

class str {
public:
    static size_t count_len(const char* s) {
        size_t i = 0;
        while (s[i]) {
            ++i;
        }
        return i;
    }
};

int main() {
    const char* testString = "Hello, World!";
    size_t length = str::count_len(testString);
    std::cout << "Length of the string: " << length << std::endl;
    return 0;
}
