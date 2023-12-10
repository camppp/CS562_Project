#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_args_list(const string& command) {
    vector<string> arg_list;
    string arg;
    bool in_quotes = false;

    for (int i = 0; i < command.size(); i++) {
        char c = command[i];
        if (c == ' ' && !in_quotes) {
            arg_list.push_back(arg);
            arg = "";
        } else if (c == '"') {
            in_quotes = !in_quotes;
        } else {
            arg += c;
        }
    }

    if (!arg.empty()) {
        arg_list.push_back(arg);
    }

    return arg_list;
}
