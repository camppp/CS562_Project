#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to convert tokens to numerical values
double tokenToValue(string token) {
    if (token == "+") {
        return 1;
    } else if (token == "-") {
        return -1;
    } else {
        return stod(token);
    }
}

// Function to perform addition operation
double op_add(vector<string> tokens) {
    double result = 0;
    for (int i = 0; i < tokens.size(); i++) {
        result += tokenToValue(tokens[i]);
    }
    return result;
}

// Function to perform subtraction operation
double op_sub(vector<string> tokens) {
    double result = 0;
    for (int i = 0; i < tokens.size(); i++) {
        result -= tokenToValue(tokens[i]);
    }
    return result;
}

int main() {
    vector<string> tokens = {"1", "+", "2", "-", "3"};
    cout << op_add(tokens) << endl; // Output: 3
    cout << op_sub(tokens) << endl; // Output: -4
    return 0;
}
