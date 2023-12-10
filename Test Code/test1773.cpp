#include <iostream>
#include <vector>
#include <string>

class BraceExpansion {
public:
    static std::vector<std::string> braceExpansion(const std::string& input) {
        std::vector<std::string> result;
        std::string current;
        expand(input, 0, current, result);
        return result;
    }

private:
    static void expand(const std::string& input, size_t index, std::string& current, std::vector<std::string>& result) {
        if (index == input.size()) {
            result.push_back(current);
            return;
        }

        if (input[index] == '{') {
            size_t end = input.find('}', index);
            size_t start = index + 1;
            while (start < end) {
                if (input[start] == ',') {
                    expand(input, end + 1, current, result);
                    start++;
                } else {
                    current.push_back(input[start]);
                }
                start++;
            }
            expand(input, end + 1, current, result);
            while (current.size() > end - index) {
                current.pop_back();
            }
        } else {
            current.push_back(input[index]);
            expand(input, index + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    std::string input = "{a,b}c{d,e}";
    std::vector<std::string> output = BraceExpansion::braceExpansion(input);
    for (const auto& str : output) {
        std::cout << str << " ";
    }
    return 0;
}
