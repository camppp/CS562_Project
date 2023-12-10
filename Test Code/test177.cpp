#include <iostream>
#include <string>
#include <vector>

using namespace std;

string replaceMacros(string code, vector<tuple<string, string>> macros) {
    for (auto& macro : macros) {
        size_t pos = code.find(macro.first);
        while (pos != string::npos) {
            code.replace(pos, macro.first.length(), macro.second);
            pos = code.find(macro.first, pos + macro.second.length());
        }
    }
    return code;
}

int main() {
    string code = "int control = PARPORT_CONTROL_AUTOFD;";
    vector<tuple<string, string>> macros = {{"PARPORT_CONTROL_AUTOFD", "AUTOFEED"}};
    cout << replaceMacros(code, macros) << endl;
    return 0;
}
