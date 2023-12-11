#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> filterServices(const vector<string>& services, const string& pattern) {
    vector<string> result;
    for (const string& service : services) {
        if (service.find(pattern) != string::npos) {
            result.push_back(service);
        }
    }
    return result;
}

int main() {
    vector<string> services = {"glibc.*", "cckit.*", "books.*", "test.*", "*httpecho*"};
    string pattern = "test.*";
    vector<string> filteredServices = filterServices(services, pattern);
    for (const string& service : filteredServices) {
        cout << service << endl;
    }
    return 0;
}
