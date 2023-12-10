#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> countOccurrences(const string& text, const vector<string>& keywords) {
    map<string, int> counts;
    for (const string& keyword : keywords) {
        int count = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text.substr(i, keyword.size()) == keyword) {
                count++;
            }
        }
        counts[keyword] = count;
    }
    return counts;
}

int main() {
    string text = "POSSIBILITY OF SUCH DAMAGE.";
    vector<string> keywords = {"POSSIBILITY", "such", "damage", "license"};
    map<string, int> counts = countOccurrences(text, keywords);
    for (const auto& count : counts) {
        cout << count.first << ": " << count.second << endl;
    }
    return 0;
}
