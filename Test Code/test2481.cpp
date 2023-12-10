#include <string>
using namespace std;

int convertBase26ToDecimal(const string& s) {
    int result = 0, base = 1;
    char c = char('A' - 1);
    for (int i = s.size() - 1; i >= 0; --i) {
        result += (s[i] - c) * base;
        base *= 26;
    }
    return result;
}
