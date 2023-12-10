#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Open the file containing the file names
    ifstream file("file_names.txt");
    if (!file) {
        cerr << "Error: unable to open file" << endl;
        return 1;
    }

    // Read the file names line by line
    string line;
    vector<string> file_names;
    while (getline(file, line)) {
        file_names.push_back(line);
    }

    // Modify the file names as described above
    for (string& file_name : file_names) {
        if (file_name.starts_with("P")) {
            file_name.replace(0, 7, ".conll");
        }
    }

    // Append the modified file names to the fromPath and toPath
    string fromPath = "from_path/";
    string toPath = "to_path/";
    for (string& file_name : file_names) {
        fromPath += file_name;
        toPath += file_name;
    }

    // Attempt to perform some operations using the modified file names
    // Handle any potential exceptions that may occur during the operations
    try {
        // Perform some operations using the modified file names
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    // Generate a report based on the processing results
    cout << "Processing results:" << endl;
    for (string& file_name : file_names) {
        cout << file_name << endl;
    }

    return 0;
}
