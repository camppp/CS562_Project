#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> remove_phonies(const vector<string>& strings) {
    vector<string> result;
    for (const string& s : strings) {
        if (s.find("phony") == string::npos) {
            result.push_back(s);
        }
    }
    return result;
}
