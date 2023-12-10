#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<string>> generate_font(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: unable to open file " << filename << endl;
        return {};
    }

    int n, m;
    file >> n >> m;

    unordered_map<char, vector<string>> font;
    for (int i = 0; i < n; i++) {
        char c;
        file >> c;
        vector<string> bitmap;
        for (int j = 0; j < m; j++) {
            string line;
            file >> line;
            bitmap.push_back(line);
        }
        font[c] = bitmap;
    }

    return font;
}
