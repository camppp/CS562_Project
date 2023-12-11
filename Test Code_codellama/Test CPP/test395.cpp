#include <iostream>
#include <regex>

int main() {
    std::string code = "int main() {\n"
                       "#ifdef LOCAL\n"
                       "    freopen(\"/Users/didi/ACM/in.txt\", \"r\", stdin);\n"
                       "#endif\n"
                       "    // Other code\n"
                       "#ifdef DEBUG\n"
                       "    cout << \"Debug mode\" << endl;\n"
                       "#endif\n"
                       "}";

    std::regex ifdef_regex("^#ifdef");
    std::regex endif_regex("^#endif");

    int count = 0;
    for (std::sregex_iterator it(code.begin(), code.end(), ifdef_regex), end; it != end; ++it) {
        count++;
    }

    for (std::sregex_iterator it(code.begin(), code.end(), endif_regex), end; it != end; ++it) {
        count--;
    }

    std::cout << "Number of conditional compilation directives: " << count << std::endl;

    return 0;
}
