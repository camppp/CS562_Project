#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("license.txt");
    string copyright_notice, list_of_conditions, disclaimer;

    while (getline(file, line)) {
        if (line == "COPYRIGHT NOTICE:") {
            copyright_notice = "";
        } else if (line == "LIST OF CONDITIONS:") {
            list_of_conditions = "";
        } else if (line == "DISCLAIMER:") {
            disclaimer = "";
        } else if (line == "") {
            break;
        } else {
            if (copyright_notice != "") {
                copyright_notice += "\n";
            }
            if (list_of_conditions != "") {
                list_of_conditions += "\n";
            }
            if (disclaimer != "") {
                disclaimer += "\n";
            }
            copyright_notice += line;
            list_of_conditions += line;
            disclaimer += line;
        }
    }

    cout << "Copyright Notice:" << endl;
    cout << copyright_notice << endl;
    cout << "List of Conditions:" << endl;
    cout << list_of_conditions << endl;
    cout << "Disclaimer:" << endl;
    cout << disclaimer << endl;

    return 0;
}
