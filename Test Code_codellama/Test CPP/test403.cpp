#include <string>
#include <vector>
#include <iostream>

using namespace std;

tuple<string, string> parse_documentation(const string& comment) {
    vector<string> tokens;
    string return_value, function_name;

    // Split the comment into tokens
    stringstream ss(comment);
    while (ss >> token) {
        tokens.push_back(token);
    }

    // Check if the comment contains the "return" tag
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "return") {
            return_value = tokens[i + 1];
            break;
        }
    }

    // Check if the comment contains the "see" tag
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "see") {
            function_name = tokens[i + 1];
            break;
        }
    }

    return make_tuple(return_value, function_name);
}

int main() {
    string comment = "/// \treturn 42\n/// \tsee lift_t";
    auto [return_value, function_name] = parse_documentation(comment);
    cout << "Return value: " << return_value << endl;
    cout << "Function name: " << function_name << endl;
    return 0;
}
