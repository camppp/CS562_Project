#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to parse and extract information from the LEEStructLang code snippet
void parseLEEStructLangCode(string code) {
    // Initialize variables to store the color and text
    int color[3] = {0, 0, 0};
    string text;

    // Find the first occurrence of the color<...> function
    size_t pos = code.find("color<");

    // If the color<...> function is found, extract the color and text
    if (pos != string::npos) {
        // Extract the color from the function call
        string colorStr = code.substr(pos + 6, 3);
        color[0] = stoi(colorStr[0]);
        color[1] = stoi(colorStr[1]);
        color[2] = stoi(colorStr[2]);

        // Extract the text from the function call
        text = code.substr(pos + 10);

        // Find the next occurrence of the color<...> function
        pos = code.find("color<", pos + 1);
    }

    // Find the first occurrence of the method call
    pos = code.find("is.getEnact().getEnactage().getLocation()");

    // If the method call is found, extract the return value
    if (pos != string::npos) {
        // Extract the return value from the method call
        string returnValue = code.substr(pos + 30);

        // Print the extracted information
        cout << "Color: " << color[0] << ", " << color[1] << ", " << color[2] << endl;
        cout << "Text: " << text << endl;
        cout << "Method Call: is.getEnact().getEnactage().getLocation()" << endl;
        cout << "Method Return Value: " << returnValue << endl;
    }

    // Find the next occurrence of the method call
    pos = code.find("is.getEnact().getEnactage().getTemporal()");

    // If the method call is found, extract the return value
    if (pos != string::npos) {
        // Extract the return value from the method call
        string returnValue = code.substr(pos + 30);

        // Print the extracted information
        cout << "Color: " << color[0] << ", " << color[1] << ", " << color[2] << endl;
        cout << "Text: " << text << endl;
        cout << "Method Call: is.getEnact().getEnactage().getTemporal()" << endl;
        cout << "Method Return Value: " << returnValue << endl;
    }
}

int main() {
    // Test the parseLEEStructLangCode function
    string code = "color<34, 34, 34> (3) is.getEnact().getEnactage().getLocation() color<32> <==> is.getEnact().getEnactage().getLocation() color<34, 34, 34> (4) is.getEnact().getEnactmentL().getRank() color<32> <==> is.getEnact().getEnactage().getTemporal()";
    parseLEEStructLangCode(code);

    return 0;
}
