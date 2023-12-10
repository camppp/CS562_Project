#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> categorize_licenses(const vector<string>& licenses) {
    map<string, vector<string>> categories;
    for (const string& license : licenses) {
        string category;
        if (license.starts_with("BSD")) {
            category = "BSD";
        } else if (license.starts_with("MIT")) {
            category = "MIT";
        } else {
            category = "Other";
        }
        categories[category].push_back(license);
    }
    return categories;
}

int main() {
    vector<string> licenses = {"MIT-2.0", "GPL-3.0", "BSD-3-Clause", "Apache-2.0", "BSD-2-Clause", "MIT-1.1"};
    map<string, vector<string>> categories = categorize_licenses(licenses);
    for (const auto& category : categories) {
        cout << category.first << ": ";
        for (const auto& license : category.second) {
            cout << license << " ";
        }
        cout << endl;
    }
    return 0;
}
