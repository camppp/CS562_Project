#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parseArguments(const vector<string>& args) {
    map<string, string> parsedArgs;
    vector<string> standaloneArgs;

    for (int i = 1; i < args.size(); i++) {
        string arg = args[i];
        if (arg.size() > 1 && arg[0] == '-') {
            // Option with value
            string option = arg.substr(1);
            string value = "";
            if (i + 1 < args.size() && args[i + 1][0] != '-') {
                value = args[i + 1];
                i++;
            }
            parsedArgs[option] = value;
        } else {
            // Standalone argument
            standaloneArgs.push_back(arg);
        }
    }

    return {parsedArgs, standaloneArgs};
}

int main() {
    vector<string> args = {"./program", "-f", "file.txt", "--output=output.txt", "arg1", "arg2"};
    auto parsedArgs = parseArguments(args);
    cout << "Parsed options: " << endl;
    for (auto& [option, value] : parsedArgs) {
        cout << option << ": " << value << endl;
    }
    cout << "Standalone arguments: " << endl;
    for (auto& arg : parsedArgs.second) {
        cout << arg << endl;
    }
    return 0;
}
