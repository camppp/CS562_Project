#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    string repoName = input.substr(input.find("<reponame>") + 10, input.find("<gh_stars>") - (input.find("<reponame>") + 10));
    string starRange = input.substr(input.find("<gh_stars>") + 9);

    cout << "Repository Name: " << repoName << endl;

    int lowerBound, upperBound;
    stringstream ss(starRange);
    char dash;
    ss >> lowerBound >> dash >> upperBound;

    cout << "Stars: ";
    for (int i = lowerBound; i <= upperBound; ++i) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
