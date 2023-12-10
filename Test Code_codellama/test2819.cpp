#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> extractNamespaceHierarchy(string code) {
    vector<string> hierarchy;
    string currentNamespace = "";
    bool inNamespace = false;

    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        if (c == '{' && inNamespace) {
            hierarchy.push_back(currentNamespace);
            currentNamespace = "";
            inNamespace = false;
        } else if (c == '}' && !inNamespace) {
            inNamespace = true;
        } else if (c == ' ' && !inNamespace) {
            currentNamespace += c;
        }
    }

    return hierarchy;
}

int main() {
    string code = "namespace xe { namespace ui { namespace spirv { // code here } } }";
    vector<string> hierarchy = extractNamespaceHierarchy(code);
    for (string namespace : hierarchy) {
        cout << namespace << endl;
    }
    return 0;
}
