#include <iostream>
#include <string>
#include <vector>

using namespace std;

string formatText(string text, vector<string> operations) {
    string formattedText = text;
    for (string operation : operations) {
        if (operation == "bold") {
            formattedText = "**" + formattedText + "**";
        } else if (operation == "italic") {
            formattedText = "_" + formattedText + "_";
        } else if (operation == "underline") {
            formattedText = "~" + formattedText + "~";
        }
    }
    return formattedText;
}

int main() {
    string text = "Hello, World!";
    vector<string> operations = {"bold", "italic"};
    string formattedText = formatText(text, operations);
    cout << formattedText << endl;
    return 0;
}
