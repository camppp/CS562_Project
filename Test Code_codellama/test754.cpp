#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> DirectivesUpdated(const vector<string>& directives) {
    vector<string> results;
    for (const string& directive : directives) {
        string action, target;
        size_t pos = directive.find(':');
        if (pos != string::npos) {
            action = directive.substr(0, pos);
            target = directive.substr(pos + 1);
        } else {
            results.push_back("Invalid directive");
            continue;
        }

        if (action == "update") {
            // Update the specified component or entity
            results.push_back("Settings updated");
        } else if (action == "create") {
            // Create a new component or entity
            results.push_back("User created");
        } else if (action == "delete") {
            // Delete the specified component or entity
            results.push_back("Post deleted");
        } else {
            results.push_back("Invalid directive");
        }
    }
    return results;
}

int main() {
    vector<string> directives = {"update:settings", "create:user", "delete:post", "update:profile"};
    vector<string> results = DirectivesUpdated(directives);
    for (const string& result : results) {
        cout << result << endl;
    }
    return 0;
}
