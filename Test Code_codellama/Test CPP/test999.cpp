#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> sort_paths(const vector<string>& paths) {
    vector<string> sorted_paths(paths);
    sort(sorted_paths.begin(), sorted_paths.end(), [](const string& a, const string& b) {
        return a < b;
    });
    return sorted_paths;
}
