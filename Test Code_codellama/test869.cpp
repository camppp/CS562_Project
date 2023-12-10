#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string codeSnippet = "https://github.com/username/repository-name.git";
    regex pattern("https://github.com/([^/]+)/([^/]+)\\.git");
    smatch matches;
    if (regex_search(codeSnippet, matches, pattern)) {
        string owner = matches[1];
        string repositoryName = matches[2];
        cout << "Owner: " << owner << endl;
        cout << "Repository name: " << repositoryName << endl;
        cout << "Number of stars: " << matches[3] << endl;
    } else {
        cout << "Invalid code snippet" << endl;
    }
    return 0;
}
