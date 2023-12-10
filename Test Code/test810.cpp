#include <string>
#include <stack>
#include <cctype>

class Calculator {
public:
    int calculate(std::string s) {
        std::stack<int> nums;
        int num = 0;
        char sign = '+';

        for (size_t i = 0; i < s.size(); ++i) {
            if (std::isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!std::isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    nums.push(num);
                } else if (sign == '-') {
                    nums.push(-num);
                } else if (sign == '*') {
                    int prev = nums.top();
                    nums.pop();
                    nums.push(prev * num);
                } else if (sign == '/') {
                    int prev = nums.top();
                    nums.pop();
                    nums.push(prev / num);
                }
                sign = s[i];
                num = 0;
            }
        }

        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
