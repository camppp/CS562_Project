#include <string>

class StringUtil {
public:
    static std::string &toupper(std::string &str) {
        for (char &c : str) {
            c = std::toupper(c);
        }
        return str;
    }
};
