#include <iostream>
#include <streambuf>
#include <cstdio>

namespace Catch {
    class out_buff : public std::streambuf {
    public:
        out_buff(std::streambuf* sb) : std::streambuf(sb) {}

        int overflow(int c) {
            if (c == EOF) {
                return EOF;
            }
            std::cout << c;
            return 0;
        }
    };

    std::ostream& clog() {
        static out_buff out_buff(std::cout.rdbuf());
        return std::cout.rdbuf(&out_buff);
    }
}

int main() {
    Catch::clog() << "Hello, world!" << std::endl;
    return 0;
}
