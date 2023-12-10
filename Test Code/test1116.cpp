#include <iostream>
#include <string>

using namespace std;

string addStrings(string numberN, string numberM) {
    int n = numberN.size();
    int m = numberM.size();
    string result;

    // Initialize the result string with the appropriate number of leading zeros
    for (int i = 0; i < max(n, m); i++) {
        result += "0";
    }

    // Add the two numbers and store the result in the result string
    for (int i = 0; i < n; i++) {
        result[i] += numberN[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        result[i] += numberM[i] - '0';
    }

    // Return the result string
    return result;
}
