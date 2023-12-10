#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void backtrack(vector<string>& result, string& num, int target, string& expr, long long diff, long long curr, int pos) {
        if (pos == num.size()) {
            if (curr == target) {
                result.push_back(expr);
            }
            return;
        }
        
        for (int i = pos; i < num.size(); i++) {
            if (i != pos && num[pos] == '0') {
                break;
            }
            string str = num.substr(pos, i - pos + 1);
            long long val = stoll(str);
            if (pos == 0) {
                backtrack(result, num, target, expr + str, val, val, i + 1);
            } else {
                backtrack(result, num, target, expr + "+" + str, val, curr + val, i + 1);
                backtrack(result, num, target, expr + "-" + str, -val, curr - val, i + 1);
                backtrack(result, num, target, expr + "*" + str, diff * val, (curr - diff) + diff * val, i + 1);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string expr;
        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[0] == '0') {
                break;
            }
            string str = num.substr(0, i + 1);
            long long val = stoll(str);
            backtrack(result, num, target, str, val, val, i + 1);
        }
        return result;
    }
};
